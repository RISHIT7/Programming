library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity FixedPointMultiplier is
    Port (
        a : in STD_LOGIC_VECTOR(15 downto 0);  -- 16-bit input for multiplier
        b : in STD_LOGIC_VECTOR(15 downto 0);  -- 16-bit input for multiplicand
        result : out STD_LOGIC_VECTOR(31 downto 0)  -- 32-bit output result
    );
end FixedPointMultiplier;

architecture Behavioral of FixedPointMultiplier is
begin
    process
        variable result_var : INTEGER := 0;
        variable num_frac_bits : INTEGER := 8;
        variable num_int_bits : INTEGER := 8;
    begin
        for i in 0 to num_frac_bits + num_int_bits - 1 loop
            -- Check if the least significant bit of multiplier is 1
            result_var := result_var * 2;
            if b(0) = '1' then
                result_var := result_var + TO_INTEGER(SIGNED(a));
            end if;

            -- Right shift multiplier
            b := b(15 downto 1) & '0';

        end loop;

        -- Adjust the result for the fractional bits
        result_var := result_var / 2**num_frac_bits;

        -- Convert result to 32-bit binary fixed-point representation
        result <= STD_LOGIC_VECTOR(TO_SIGNED(result_var, 32));

    end process;
end Behavioral;
