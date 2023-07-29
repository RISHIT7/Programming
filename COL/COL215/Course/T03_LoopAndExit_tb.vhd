ENTITY T03_LoopAndExit_tb IS
END T03_LoopAndExit_tb;

ARCHITECTURE sim OF T03_LoopAndExit_tb IS

BEGIN
    PROCESS
    BEGIN
        REPORT "Hello!"; -- first enters the hello line
        LOOP
            REPORT "PEEKABOO!"; -- write peeekaboo
            EXIT; -- exits
        END LOOP;

        REPORT "Goog Bye!" -- writes good bye
            WAIT;
    END PROCESS;

END ARCHITECTURE;