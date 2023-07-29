LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- '1' Logic 1
-- '0' Logic 0
-- 'Z' High Impedance "Nothing"
-- 'W' Weak signal "can't tell if 0 or 1"
-- 'L' Weak 0 "pulldown"
-- 'H' Weak 1 "pullup"
-- '-' Don't Care
-- 'U' Uninitialized
-- 'X' Unkown "multiple drivers"
ENTITY T10_stdLogic_tb IS
END T10_stdLogic_tb;

ARCHITECTURE sim OF T10_stdLogic_tb IS

    SIGNAL Signal1 : STD_LOGIC := '0';
    SIGNAL Signal2 : STD_LOGIC;
    SIGNAL Signal3 : STD_LOGIC;

BEGIN

    PROCESS IS

    BEGIN

        WAIT FOR 10 ns;
        Signal1 <= NOT Signal1;

    END PROCESS;

    -- Driver A
    PROCESS IS

    BEGIN

        Signal2 <= 'Z';
        Signal3 <= '0';
        WAIT;

    END PROCESS;

    -- Driver B
    PROCESS (Signal1) IS

    BEGIN

        IF Signal1 = '0' THEN
            Signal2 <= 'Z';
            Signal3 <= 'Z';
        ELSE
            signal2 <= '1';
            signal3 <= '1';
        END IF;

    END PROCESS;

END ARCHITECTURE;