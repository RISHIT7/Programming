LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY MUX IS
    PORT (
        A, B, C, D : IN STD_LOGIC; -- the input that needed to be sent as output
        S : IN STD_LOGIC_VECTOR (1 DOWNTO 0); -- the selectors
        Z : OUT STD_LOGIC; -- output
    );
END MUX;

ARCHITECTURE sim OF MUX IS

BEGIN

    PROCESS (A, B, C, D, S) IS -- sensitivity process
        CASE S IS
            WHEN "00" =>
                Z <= A;
            WHEN "10" =>
                Z <= B;
            WHEN "01" =>
                Z <= C;
            WHEN OTHERS =>
                Z <= D;

        END CASE;
    END PROCESS;
END ARCHITECTURE;