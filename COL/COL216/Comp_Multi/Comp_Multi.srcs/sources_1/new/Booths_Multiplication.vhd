LIBRARY ieee;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.numeric_std.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY Booths_Multiplication IS
--    Port (
--    a: in std_logic_vector(15 downto 0);
--    b: in std_logic_vector(15 downto 0);
--    c: out std_logic_vector(31 downto 0);
--    clock_cycle : out integer
--    );
END Booths_Multiplication;

ARCHITECTURE Behavioral OF Booths_Multiplication IS

    SIGNAL multiplicand : STD_LOGIC_VECTOR(15 DOWNTO 0) := "1001001000101110"; --variables are 8 bits
    SIGNAL multiplier : STD_LOGIC_VECTOR(15 DOWNTO 0) := "1001001000101110";
    signal counter : INTEGER := 0;
    SIGNAL clk : STD_LOGIC := '0';
    constant bin_literal : std_logic_vector(15 downto 0) := "0000000000000000";
    SIGNAL result : STD_LOGIC_VECTOR(31 DOWNTO 0); --result of multipication can be at most 16 bits
    SIGNAL s : STD_LOGIC;
    signal clock_num : integer := 0;
    CONSTANT clock_period : TIME := 20 ns;
BEGIN
    PROCESS
    BEGIN
        WAIT FOR clock_period/2;
        clk <= NOT clk;
    END PROCESS;

    PROCESS (clk)

        VARIABLE arr : STD_LOGIC_VECTOR(31 DOWNTO 0);

    BEGIN

        IF (rising_edge(clk) AND counter < 17) THEN

            IF (counter = 0) THEN --first level : initializing arr
                arr (15 DOWNTO 0) := multiplicand;

                arr (31 DOWNTO 16) := bin_literal;

                s <= '0';

            ELSIF (arr (0) = '0' AND s = '1') THEN --Based on table
                arr (31 DOWNTO 16) := arr (31 DOWNTO 16) + multiplier;

                s <= arr (0); --Previous value is move down to result

                arr (30 DOWNTO 0) := arr (31 DOWNTO 1); --shift to right (it act like shift to left when we write
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