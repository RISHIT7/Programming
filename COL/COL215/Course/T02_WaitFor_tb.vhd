ENTITY T02_WaitFor_tb IS
END ENTITY;

ARCHITECTURE sim OF T02_WaitFor_tb IS
BEGIN
    PROCESS IS

    BEGIN
        REPORT "peekaboo";

        WAIT FOR 10 ns; -- This makes the simulator wait for 10 ns, rather than wait, which makes the prgram stop
    END PROCESS;

END ARCHITECTURE;