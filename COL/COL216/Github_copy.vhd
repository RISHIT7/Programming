LIBRARY ieee;

USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
ENTITY Booths_Multiplication IS
    --port (

    --        multiplier, multiplicand: in  std_logic_vector(7 downto 0);  --variables are 8 bits
    --		   clk   : in  std_logic;
    --			result     : out std_logic_vector(15 downto 0)  --result of multipication can be at most 16 bits
    --		);
END Booths_Multiplication;

ARCHITECTURE Behavioral OF Booths_Multiplication IS

    CONSTANT clock_period : TIME := 10 ns;
    SIGNAL multiplicand : STD_LOGIC_VECTOR(7 DOWNTO 0) := "10010011"; --variables are 8 bits
    SIGNAL multiplier : STD_LOGIC_VECTOR(7 DOWNTO 0) := "10010011";
    SIGNAL clk : STD_LOGIC := '0';
    SIGNAL result : STD_LOGIC_VECTOR(15 DOWNTO 0); --result of multipication can be at most 16 bits

    SIGNAL counter : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0000"; --because we have 9 level

    SIGNAL s : STD_LOGIC;

BEGIN

    PROCESS
    BEGIN
        WAIT FOR clock_period/2;
        clk <= NOT clk;
    END PROCESS;

    PROCESS (clk)

        VARIABLE arr : STD_LOGIC_VECTOR(15 DOWNTO 0);

    BEGIN

        IF (clk 'event AND clk = '1' AND counter < 9) THEN

            IF (counter = "0000") THEN --first level : initializing arr
                arr (7 DOWNTO 0) := multiplicand;

                arr (15 DOWNTO 8) := "00000000";

                s <= '0';

            ELSIF (arr (0) = '0' AND s = '1') THEN --Based on table
                arr (15 DOWNTO 8) := arr (15 DOWNTO 8) + multiplier;

                s <= arr (0); --Previous value is move down to result

                arr (14 DOWNTO 0) := arr (15 DOWNTO 1); --shift to right (it act like shift to left when we write
                -- partical products in 8 row)

            ELSIF (arr (0) = '1' AND s = '0') THEN --Based on table

                arr (15 DOWNTO 8) := arr (15 DOWNTO 8) + NOT multiplier + 1;

                s <= arr (0); --Previous value is move down to result

                arr (14 DOWNTO 0) := arr (15 DOWNTO 1); --shift to right (it act like shift to left when we write
                -- partical products in 8 row)

            ELSE --Based on table

                s <= arr (0); --Previous value is move down to result

                arr (14 DOWNTO 0) := arr (15 DOWNTO 1); --shift to right (it act like shift to left when we write
                -- partical products in 8 row)

            END IF;

            counter <= counter + 1; --increasing counter

        END IF;

        result <= arr; --result of multipication

    END PROCESS;

END Behavioral;