library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity FixedPointMultiplier is
    Port (
        a : in STD_LOGIC_VECTOR(15 downto 0);  -- 16-bit input for multiplier
        b : in STD_LOGIC_VECTOR(15 downto 0);  -- 16-bit input for multiplicand
        result : out STD_LOGIC_VECTOR(31 downto 0)  -- 32-bit output result
        clk : in STD_LOGIC;
        rst : in STD_LOGIC;
    );
end FixedPointMultiplier;

architecture Behavioral of FixedPointMultiplier is
    signal counter : INTEGER := 0;
begin
    process(clk, rst)
        variable result_var : INTEGER := 0;
        variable num_bits : INTEGER := 16;
    begin
        if rst = '1' then
            result_var := 0;

        elsif rising_edge(clk) then
            if counter < 16 then
                if b(0) = '1' then
                    result_var := result_var + TO_INTEGER(UNSIGNED(a));
                end if;

                a <= a sl1 1; -- shift left
                b <= shift_right(b, 1); -- shift right

                counter <= counter + 1;

            else 
                -- Convert result to 32-bit binary fixed-point representation
                result <= STD_LOGIC_VECTOR(TO_UNSIGNED(result_var, 32));
            end if;
        end if;
    end process;
end Behavioral;
