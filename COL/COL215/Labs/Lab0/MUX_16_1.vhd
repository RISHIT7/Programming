LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY MUX_16_1 IS
    PORT (
        input_vec : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
        intermediate : STD_LOGIC_VECTOR (3 DOWNTO 0);
        output_vec : OUT STD_LOGIC_VECTOR (6 DOWNTO 0);
        an : STD_LOGIC_VECTOR (3 DOWNTO 0);
    );
END MUX_16_1;

ARCHITECTURE sim OF MUX_16_1 IS
    SIGNAL S : STD_LOGIC_VECTOR (1 DOWNTO 0) := (OTHERS => '0');

BEGIN;

    PROCESS (input_vec) IS
    BEGIN
        intermediate(0) <= input_vec(3) * (2 * 2 * 2) + input_vec(2) * (2 * 2) + input_vec(1) * (2) + input_vec(0);
        intermediate(1) <= input_vec(7) * (2 * 2 * 2) + input_vec(6) * (2 * 2) + input_vec(5) * (2) + input_vec(4);
        intermediate(2) <= input_vec(11) * (2 * 2 * 2) + input_vec(10) * (2 * 2) + input_vec(9) * (2) + input_vec(8);
        intermediate(3) <= input_vec(15) * (2 * 2 * 2) + input_vec(14) * (2 * 2) + input_vec(13) * (2) + input_vec(12);
    END PROCESS;

    PROCESS (intermediate) IS
    BEGIN
        WAIT FOR 10 ns;
        S <= S + 1;
    END PROCESS;

    PROCESS (S) IS
    BEGIN;
        CASE S IS
            WHEN "00" =>
                an <= "0001";
                IF intermediate(0) = x"1" THEN
                    output_vec <= "0110110";
                ELSIF intermediate(0) = x"2" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"3" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"4" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"5" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"6" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"7" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"8" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"9" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"A" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"B" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"C" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"D" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"E" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(0) = x"F" THEN
                    output_vec <= "0101010";
                END IF;
            WHEN "01" =>
                an <= "0010";
                IF intermediate(1) = x"1" THEN
                    output_vec <= "0110110";
                ELSIF intermediate(1) = x"2" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"3" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"4" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"5" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"6" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"7" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"8" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"9" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"A" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"B" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"C" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"D" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"E" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(1) = x"F" THEN
                    output_vec <= "0101010";
                END IF;

            WHEN "10" =>
                an <= "0100";
                IF intermediate(2) = x"1" THEN
                    output_vec <= "0110110";
                ELSIF intermediate(2) = x"2" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"3" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"4" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"5" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"6" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"7" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"8" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"9" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"A" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"B" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"C" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"D" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"E" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(2) = x"F" THEN
                    output_vec <= "0101010";
                END IF;

            WHEN "11" =>
                an <= "1000";
                IF intermediate(3) = x"1" THEN
                    output_vec <= "0110110";
                ELSIF intermediate(3) = x"2" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"3" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"4" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"5" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"6" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"7" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"8" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"9" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"A" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"B" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"C" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"D" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"E" THEN
                    output_vec <= "0101010";
                ELSIF intermediate(3) = x"F" THEN
                    output_vec <= "0101010";
                END IF;
        END CASE;
    END PROCESS;

END ARCHITECTURE;