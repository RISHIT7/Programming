-- wait statements are only used in test benches, however in development files, we use sensitivity lists rather
ENTITY T09_Sensitivity_tb IS
END T09_Sensitivity_tb;

ARCHITECTURE sim OF T09_Sensitivity_tb IS

    SIGNAL CountUp : INTEGER := 0;
    SIGNAL CountDown : INTEGER := 10;
BEGIN

    PROCESS IS
    BEGIN

        CountUp <= CountUp + 1;
        CountDown <= CountDown - 1;
        WAIT FOR 10 ns;

    END PROCESS;

    -- Process triggered using wait on
    PROCESS IS
    BEGIN

        IF CountUp = CountDown THEN
            REPORT "Process A: jackpot!";

            WAIT ON CountUp, CountDown; -- wait statements are generally added at the end of the process
        END IF;

    END PROCESS;

    -- sensitivity list
    PROCESS (CountUp, Countdown) IS
    BEGIN

        IF CountUp = CountDown THEN
            REPORT "Process B: jackpot!";
        END IF;

    END PROCESS;

END ARCHITECTURE;