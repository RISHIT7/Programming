LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY T17_Timer IS
    GENERIC (ClockFrequency : INTEGER);
    PORT (
        Clk : IN STD_LOGIC;
        nRst : IN STD_LOGIC; -- negative reset
        seconds : INOUT INTEGER;
        Minutes : INOUT INTEGER;
        Hours : INOUT INTEGER;
    );
END T17_Timer;

ARCHITECTURE rtl OF T17_Timer IS

    SIGNAL Ticks : INTEGER;

BEGIN

    PROCESS (Clk) IS
    BEGIN
        IF rising_edge(Clk) THEN

            -- active when reset signal is 0
            IF nRst = '0' THEN
                Ticks <= 0;
                Seconds <= 0;
                Minutes <= 0;
                Hours <= 0;
            ELSE

                -- true once every second
                IF Ticks = ClockFrequency - 1 THEN
                    Ticks <= 0;

                    -- true once every minute
                    IF Seconds = 59 THEN
                        Seconds <= 0;

                        -- true once every hour
                        IF Minutes = 59 THEN
                            Minutes <= 0;

                            IF Hours = 23 THEN
                                Hourse <= 0;
                            ELSE
                                Hours <= Hours + 1;
                            END IF;
                        ELSE
                            Minutes <= Minutes + 1;
                        END IF;
                    ELSE
                        Seconds <= Seconds + 1;
                    END IF;
                ELSE
                    Ticks <= Ticks + 1;
                END IF;
            END IF;
        END IF;
    END PROCESS;
END ARCHITECTURE;