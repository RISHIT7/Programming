-- scope of a variable is only in the process where it was declared
-- but if we wanted to do anything outside the process, we will need to do something else

ENTITY T06_Signal_tb IS
END T06_Signal_tb;

ARCHITECTURE sim OF T06_Signal_tb IS

    SIGNAL MySignal : INTEGER := 0;

BEGIN
    PROCESS IS
        VARIABLE MyVariable : INTEGER := 0;
    BEGIN

        MyVariable := MyVariable + 1;
        MySignal <= MySignal + 1; -- Just the way we define  signal

        REPORT "MyVariable = " & INTEGER'image(MyVariable) &
            ", MySignal = " & INTEGER'image(MySignal);

        MyVariable := MyVariable + 1;
        MySignal <= MySignal + 1; -- Just the way we define  signal

        REPORT "MyVariable = " & INTEGER'image(MyVariable) &
            ", MySignal = " & INTEGER'image(MySignal);

        WAIT FOR 10 ns;
        -- when we print the outputs, we see that variables are updated immediately, whereas it takes a pause statement for the signal to update
        -- And it is the last assignment before the pause statment that will be applied on the signal
    END PROCESS;

END ARCHITECTURE;