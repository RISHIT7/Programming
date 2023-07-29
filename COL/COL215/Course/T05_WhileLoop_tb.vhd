ENTITY T05_WhileLoop_tb IS
END T05_WhileLoop_tb;

ARCHITECTURE sim OF T05_WhileLoop_tb IS

BEGIN

    PROCESS IS
        VARIABLE i : INTEGER := 0;
    BEGIN

        WHILE i < 10 LOOP
            REPORT "i=" & INTEGER'image(i);
            i := i + 2;
        END PROCESS;
        WAIT;

    END ARCHITECTURE;