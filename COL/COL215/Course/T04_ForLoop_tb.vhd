ENTITY T04_ForLoop_tb IS
END T04_ForLoop_tb;

ARCHITECTURE sim OF T04_ForLoop_tb IS

BEGIN

    PROCESS IS
    BEGIN

        FOR i IN 1 TO 10 LOOP
            REPORT "i=" & INTEGER'image(i); -- Integer'image(i) is used to convert to string, and & is used to concatenate
        END LOOP;
        WAIT;

    END PROCESS;

END ARCHITECTURE;