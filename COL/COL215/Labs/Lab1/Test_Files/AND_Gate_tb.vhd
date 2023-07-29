LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- no ports for tb hence an empty entity
ENTITY AND_Gate_tb IS
END AND_Gate_tb;

ARCHITECTURE sim OF AND_Gate_tb IS

    COMPONENT AND_Gate -- defining the component that we want to do the test on
        PORT (
            a : IN STD_LOGIC;
            b : IN STD_LOGIC;
            c : OUT STD_LOGIC;
        );
    END COMPONENT;

    SIGNAL a, b : STD_LOGIC; -- input signals
    SIGNAL c : STD_LOGIC; -- output signals

BEGIN
    -- connecting test bench signals with AND_Gate.vhd
    UUT : AND_Gate PORT MAP(a => a, b => b, c => c); -- Unit under test

    -- inputs and their values at given times
    a <= '0', '1' AFTER 20 ns, '0' AFTER 40 ns, '1' AFTER 60 ns;
    b <= '0', '1' AFTER 40 ns;

END ARCHITECTURE;
