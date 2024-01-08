LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.numeric_std.ALL;
USE IEEE.std_logic_unsigned.ALL;

ENTITY Multiplier IS
        Port (
            a: in std_logic_vector(15 downto 0);
            b: in std_logic_vector(15 downto 0);
            clk : in std_logic;
            c: out std_logic_vector(31 downto 0);
            clock_cycle : out integer
        );
END Multiplier;

ARCHITECTURE Behavioral OF Multiplier IS
--    signal    a:  std_logic_vector(15 downto 0) := "0100110111101011";
--    signal    b:  std_logic_vector(15 downto 0) := "0001000101000000";
--    signal    c:  std_logic_vector(31 downto 0) := (others => '0');
--    signal    clock_cycle :  integer := 0;
    SIGNAL counter : INTEGER := 0;
--    SIGNAL clk : STD_LOGIC := '0';
    CONSTANT bin_literal : STD_LOGIC_VECTOR(15 DOWNTO 0) := "0000000000000000";
    SIGNAL multiplier : STD_LOGIC_VECTOR(15 DOWNTO 0) := (others => '0');
    SIGNAL multiplicand : STD_LOGIC_VECTOR(31 DOWNTO 0) := (others => '0');
    SIGNAL result : STD_LOGIC_VECTOR(31 DOWNTO 0) := (OTHERS => '0');
    SIGNAL clock_num : INTEGER := 0;
--    CONSTANT clock_period : TIME := 10ns;
BEGIN
--    PROCESS
--    BEGIN
--        WAIT FOR clock_period/2;
--        clk <= NOT clk;
--    END PROCESS;

    PROCESS (clk)

    BEGIN
        IF rising_edge(clk) THEN
            if counter = 0 then
                multiplicand <= bin_literal & a;
                multiplier <= b;
            elsif counter < 17 THEN
                IF multiplier(0) = '1' THEN
                    result <= STD_LOGIC_VECTOR(unsigned(result)) + STD_LOGIC_VECTOR(unsigned(multiplicand));
                END IF;
                multiplicand <= STD_LOGIC_VECTOR(shift_left(unsigned(multiplicand), 1));
                multiplier <= STD_LOGIC_VECTOR(shift_right(unsigned(multiplier), 1));
                clock_num <= clock_num + 1;
            end if;
            counter <= counter + 1;
            
            
            c <= result;
            clock_cycle <= clock_num;            
        END IF;
            
    END PROCESS;
    


END Behavioral;