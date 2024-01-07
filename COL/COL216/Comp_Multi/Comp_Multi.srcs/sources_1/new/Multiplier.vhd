library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;
use IEEE.std_logic_unsigned.ALL;

entity Multiplier is
--    Port (
--    a: in std_logic_vector(15 downto 0);
--    b: in std_logic_vector(15 downto 0);
--    c: out std_logic_vector(31 downto 0);
--    clock_cycle : out integer
--    );
end Multiplier;

architecture Behavioral of Multiplier is
    signal a : std_logic_vector(15 downto 0) := "1001001000101110";
    signal b : std_logic_vector(15 downto 0) := "1001001000101110";
    signal counter : INTEGER := 0;
    signal add_count : INTEGER := 0;
    signal clk : std_logic := '0';
    signal multiplier : std_logic_vector(15 downto 0) := b;
    signal multiplicand : std_logic_vector(15 downto 0):= a;
    signal result : std_logic_vector(31 downto 0) := (others => '0');
    signal clock_num : integer := 0;
    signal result_var :INTEGER := 0;
    constant clock_period : time  := 10ns;
begin
    process
    begin
        wait for clock_period/2;
        clk <= not clk;
    end process;

    process(clk)
        
    begin
        if rising_edge(clk) then
            if counter < 16 then
                if multiplier(0) = '1' then
                    result_var <= result_var + TO_INTEGER(unsigned(a));
                    add_count <= add_count + 1;
                end if;
                multiplicand <= std_logic_vector(shift_left(unsigned(multiplicand), 1));
                multiplier <= std_logic_vector(shift_right(unsigned(multiplier), 1));
                counter <= counter + 1;
                
            else
                result <= std_logic_vector(TO_UNSIGNED(result_var, 32));
            end if;
        end if;
    end process;
end Behavioral;
