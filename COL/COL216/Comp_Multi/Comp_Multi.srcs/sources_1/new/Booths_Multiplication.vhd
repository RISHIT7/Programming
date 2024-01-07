library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;
use IEEE.std_logic_unsigned.ALL;

entity Booths_Multiplier is
--    Port (
--    a: in std_logic_vector(15 downto 0);
--    b: in std_logic_vector(15 downto 0);
--    c: out std_logic_vector(31 downto 0);
--    clock_cycle : out integer
--    );
end Booths_Multiplier;

architecture Behavioral of Booths_Multiplier is
    signal a : signed(15 downto 0) := "1001001000101110";
    signal b : signed(15 downto 0) := "1001001000101110";
    signal counter : INTEGER := 0;
    signal bin_literal : signed(15 downto 0) := "0000000000000000";   
    signal clk : std_logic := '0';
    signal multiplicand : signed(31 downto 0) := a & bin_literal;
    signal multiplier : signed(15 downto 0) := b; -- Q
    signal result : signed(31 downto 0) := (others => '0');
    signal clock_num : integer := 0;
    constant clock_period : time  := 20ns;
begin
    process
    begin
        wait for clock_period/2;
        clk <= not clk;
    end process;

    process(clk)
      variable result_var : signed(31 downto 0) := bin_literal & multiplier;
--    variable temp_multiplicand : INTEGER := to_integer(unsigned(a)) * (2);
    begin
        if rising_edge(clk) then
            if counter < 16 then
--                case multiplier(1 downto 0) is
--                    when "01" =>
----                        result_var <= result_var + temp_multiplicand;
--                          result <= (signed(result) + signed(multiplicand));
--                        clock_num <= clock_num + 1;
--                    when "10" =>
----                        result_var <= result_var - temp_multiplicand;
--                          result <= (signed(result) - signed(multiplicand));
--                        clock_num <= clock_num + 1;
--                    when others =>
--                        null;
--                end case;
                
                    if multiplier( 1 downto 0 ) = "01" then
--                        result_var <= result_var + temp_multiplicand;
                          result_var := result_var + multiplicand;
                        clock_num <= clock_num + 1;
                    elsif multiplier (1 downto 0) = "10" then
--                        result_var <= result_var - temp_multiplicand;
                          result_var := result_var - multiplicand;
                        clock_num <= clock_num + 1;
                    
                    end if;
                
                multiplier <= '0' & multiplier(15 downto 1);
--                result_var <= result_var/2;
                result_var := '0' & result_var(31 downto 1);
                
                counter <= counter + 1;
                
--            else
                result <= result_var;
            end if;
        end if;
    end process;
end Behavioral;

