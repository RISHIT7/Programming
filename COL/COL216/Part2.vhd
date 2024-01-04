library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity BoothsMultiplication is
    Port (
        clk : in STD_LOGIC;
        rst : in STD_LOGIC;
        multiplier : in STD_LOGIC_VECTOR(15 downto 0);
        multiplicand : in STD_LOGIC_VECTOR(15 downto 0);
        result : out STD_LOGIC_VECTOR(31 downto 0)
    );
end entity BoothsMultiplication;

architecture Behavioral of BoothsMultiplication is
    signal Q: STD_LOGIC_VECTOR(15 downto 0);
    signal counter : INTEGER := 0;
begin
    process(clk, rst)
    begin
        if rst = '1' then
            counter <= 0;
            Q <= (others => '0');
        elsif rising_edge(clk) then
            -- Perform Booth's algorithm
            if counter < 16 then
                -- Check the least significant two bits of the multiplier
                case Q(1 downto 0) is
                    when "01" =>
                        -- result <= result + (multiplicand & "0000");
                    when "10" =>
                        -- result <= result - (multiplicand & "0000");
                end case;

                -- Arithmetic right shift the multiplier and the accumulator
                Q <= '0' & Q(15 downto 1);
                result <= '0' & result(31 downto 1);

                counter <= counter + 1;
            else
                result <= shift_left(result, 1);

                -- Reset counter and intermediate signals
                counter <= 0;
                Q <= (others => '0');
                A <= (others => '0');
            end if;
        end if;
    end process;
end architecture Behavioral;
