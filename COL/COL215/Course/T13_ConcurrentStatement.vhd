LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY T13_ConcurrentStatement IS;
END ENTITY;

ARCHITECTURE sim OF T13_ConcurrentStatement IS

    SIGNAL Uns : unsigned (5 DOWNTO 0) := (OTHERS => '0');
    SIGNAL Mull : unsigned (7 DOWNTO 0);

BEGIN

    PROCESS IS
    BEGIN

        Uns <= Uns + 1;

        WAIT FOR 10 ns;
    END PROCESS

    -- Process multiplying Uns by
    PROCESS IS
    BEGIN
        Mull <= Uns & "00";
        WAIT ON Uns;
    END PROCESS;

END ARCHITECTURE;