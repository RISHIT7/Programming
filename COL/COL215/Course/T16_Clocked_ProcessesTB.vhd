LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std;

ENTITY T16_Clocked_ProcessesTB IS
END T16_Clocked_ProcessesTB;

ARCHITECTURE sim OF T16_Clocked_ProcessesTB IS

    CONSTANT ClockFrequency : INTEGER := 100e6; -- 100 Mhz
    CONSTANT ClockPeriod : TIME := 1000 ms / ClockFrequency;

    SIGNAL Clk : STD_LOGIC := '1';

BEGIN

    i_FlipFlop : ENTITY work.T16_Clocked_ProcessesTB(rtl) PORT MAP(
        Clk => Clk,
        nRst => nRst,
        Input => Input;
        Output => Output;
        );

    -- process for generating a clock
    Clk <= NOT Clk AFTER ClockPeriod/2;

    PROCESS IS
    BEGIN
        nRst <= '1';

        WAIT FOR 20 ns;
        Input <= '1';
        WAIT FOR 22 ns;
        Input <= '0';
        WAIT FOR 6 ns;
        Input <= '1';
        WAIT FOR 20 ns;

        nRst <= '0';
        WAIT;
    END ARCHITECTURE; -- sim