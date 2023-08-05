LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std;

ENTITY T16_FlipFlop IS
    PORT (
        Clk : IN STD_LOGIC;
        nRst : IN STD_LOGIC;
        Input : IN STD_LOGIC;
        Output : IN STD_LOGIC;
    );
END T16_FlipFlop;

ARCHITECTURE rtl OF T16_FlipFlop IS

BEGIN

    PROCESS (Clk) IS
    BEGIN
        IF rising_edge(Clk) THEN
            IF nRst = '0' THEN
                Output <= '0';
            ELSE
                Output <= Input;
            END IF;
        END IF;
    END PROCESS;

END ARCHITECTURE; -- rtl