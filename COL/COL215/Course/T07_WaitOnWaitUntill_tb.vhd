ENTITY T07_WaitOnWaitUntill_tb IS
END T07_WaitOnWaitUntill_tb;

ARCHITECTURE sim OF T07_WaitOnWaitUntill_tb IS

    SIGNAL CountUp : INTEGER := 0;
    SIGNAL CountDown : INTEGER := 10;

BEGIN

    PROCESS IS
    BEGIN

        CountUp <= CountUp + 1;
        CountDown <= CountDown - 1;
        WAIT FOR 10 ns;
    END PROCESS;

    PROCESS IS
    BEGIN

        WAIT ON CountUp, CountDown; -- uses the change in the signals to change
        REPORT "CountUp=" & INTEGER'image(CountUp) & 
            "CountDown=" & INTEGER'image(CountDown);

    END PROCESS;

    PROCESS IS
    BEGIN

        WAIT UNTIL CountUp = CountDown; -- uses precdicates for printing
        REPORT "JackPot!";

    END PROCESS;

END ARCHITECTURE;