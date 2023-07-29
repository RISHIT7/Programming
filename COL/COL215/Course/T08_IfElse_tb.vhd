ENTITY T08_IfElse_tb IS
END T08_IfElse_tb;

ARCHITECTURE sim OF T08_IfElse_tb IS

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

        IF CountUp > CountDown THEN
            REPORT "CountUp is larger";
        ELSIF CountUp < CountDown THEN
            REPORT "CountDown in larger";
        ELSE
            REPORT "They are equal";
        END IF;

        WAIT ON CountUp, CountDown; -- wait statements are generally added at the end of the process

    END PROCESS;

END ARCHITECTURE;