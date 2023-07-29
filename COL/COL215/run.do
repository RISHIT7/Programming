# This ModelSim DO-script starts or restarts the
# simulation with or without the waveform window.
#
# Usage: do run.do [wave|nowave]
#
# Example: do run.do
#          do run.do wave
#          do run.do nowave
#
# A wave/nowave flag specified on the command line
# overrides the defaultWaveFlag variable

namespace eval ::run_do {

    # Change these settings to match your project
    #
    # tbEnt:   Testbench entity
    # tcLib:   Testbench library
    # runTime: Time value (e.g., "10 ns")
    #          or "-all" to run until the finish keyword
    variable tbEnt First_tb
    variable tbLib work
    variable runTime -all

    variable defaultWaveFlag nowave
    variable waveFile wave.do

    # 0 = Note  1 = Warning  2 = Error  3 = Failure  4 = Fatal
    variable BreakOnAssertion 3

    # Don't show base (7'h, 32'd, etc.) in waveform
    if {[string first "symbolic showbase" [radix]] != -1} {
        quietly radix noshowbase
    }

    # Avoid "File modified outside of source editor" popup warning
    set PrefSource(AutoReloadModifiedFiles) 1

    # Process command-line arguments $1 to $9
    for {variable i 1} {$i < 10} {incr i} {

        if {[info exists $i]} {
            variable arg [subst "\$$i"]

            if {$arg == "wave"} {
                variable defaultWaveFlag wave
            } elseif {$arg == "nowave"} {
                variable defaultWaveFlag nowave
            } else {
                echo "DO script: unrecognized command-line argument: \"$arg\""
                echo "(Should be \"wave\" or \"nowave\")"
            }
        }
    }

    # If the design already is loaded
    if {[runStatus] != "nodesign" && [find instances -bydu -nodu $tbEnt] == "/$tbEnt"} {

        # Restart the simulation
        restart -force
        variable isRestart true

    } else {
        # Start a new simulation
        vsim -gui -onfinish stop -msgmode both -voptargs=+acc $tbLib.$tbEnt
        variable isRestart false
    }

    # This procedure is a hack to get the path to this script
    # "info script" doesn't work for ModelSim do-files
    proc getScriptDir {} {

        # Get the last command from the history
        variable histLines [split [history] "\n"]
        variable lastLineIndex [expr [llength $histLines] - 1 ]
        variable lastLine [lindex $histLines $lastLineIndex]

        # Remove all quotes
        variable trimmed [regsub -all {(\")} $lastLine {}]

        # Remove the first two words
        variable trimmed [regsub -all {(^\s*\w+\s+\w+\s+)} $trimmed {}]

        # Remove everything after the last slash
        variable trimmed [regsub -all {([^\/]*$)} $trimmed {}]

        # Trim whitespace
        variable trimmed [string trim $trimmed]

        # Remove backslashes (ModelSim uses forward slash on all platforms)
        variable trimmed [regsub -all {(\\)} $trimmed {}]

        # If the string is empty
        if {$trimmed eq ""} {
            return "./"
        }

        # The trimmed string should contain the location of this script
        return $trimmed
    }

    # Assume that the wave file is in the same dir as the run script
    variable waveFile [getScriptDir]$waveFile


    # Save the signal history, even before adding them to the
    # waveform. This slows down the simulation for large designs,
    # but it allows us to add signals to the waveform
    # without restarting the simulation after adding them.
    quietly catch log * -r

    if {$defaultWaveFlag == "wave"} {

        # If the wave window is not open
        if {[string first ".wave" [view]] == -1 || $isRestart == "false"} {

            if {![file exists $waveFile]} {
                echo "Error: Wave format file not found: \"$waveFile\""
                return
            }

            do $waveFile
        }

    } else {
        noview wave
    }

    # Run the testbench
    run $runTime
}