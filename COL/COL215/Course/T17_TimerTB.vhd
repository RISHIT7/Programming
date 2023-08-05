LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY T17_TimerTB IS
END T17_TimerTB;

ARCHITECTURE sim OF T17_TimerTB IS

-- if we slow it down too 10Hz, then we slow down the clock to speed up the simulation time
    CONSTANT ClockFrequency : INTEGER := 100e6; -- 100 MHz
    CONSTANT ClockPeriod : TIME := 1000 ms / ClockFrequency;

    SIGNAL Clk : STD_LOGIC := '1';
    SIGNAL nRst : STD_LOGIC := '0';
    SIGNAL Seconds : INTEGER;
    SIGNAL Minutes : INTEGER;
    SIGNAL Hours : INTEGER;

BEGIN

    --  The Device Under Test (DUT)
    i_Timer : ENTITY work.T17_Timer(rtl)
        GENERIC MAP(ClockFrequency => ClockFrequency)
        PORT MAP(
            Clk => Clk,
            nRst => nRst,
            Seconds => Seconds;
            Minutes => Minutes;
            Hours => Hours;
        );

    -- Process for generating the clock
    Clk <= NOT Clk AFTER ClockPeriod/2;
    PROCESS IS
    BEGIN
        WAIT UNTIL rising_edge(Clk);
        WAIT UNTIL rising_edge(Clk);

        nRst => '1';

        WAIT;
    END PROCESS;

END ARCHITECTURE; -- sim