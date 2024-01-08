LIBRARY ieee;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.numeric_std.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY Booths_Multiplication IS
    Port (
        a: in std_logic_vector(15 downto 0);
        b: in std_logic_vector(15 downto 0);
        clk : in std_logic;
        c: out std_logic_vector(31 downto 0);
        clock_cycle : out integer
    );
END Booths_Multiplication;

ARCHITECTURE Behavioral OF Booths_Multiplication IS

--    signal    a:  std_logic_vector(15 downto 0) := "0100110111101011";
--    signal    b:  std_logic_vector(15 downto 0) := "0001000101000000";
--    signal    c:  std_logic_vector(31 downto 0) := (others => '0');
--    signal    clock_cycle :  integer := 0;

--    signal counter : INTEGER := 0;
--    SIGNAL clk : STD_LOGIC := '0';
    constant bin_literal : std_logic_vector(15 downto 0) := "0000000000000000";
    SIGNAL result : STD_LOGIC_VECTOR(31 DOWNTO 0); --result of multipication can be at most 16 bits
    SIGNAL s : STD_LOGIC;
    signal clock_sig : integer := 0;
--    CONSTANT clock_period : TIME := 20 ns;
BEGIN
--    PROCESS
--    BEGIN
--        WAIT FOR clock_period/2;
--        clk <= NOT clk;
--    END PROCESS;

    PROCESS (clk)

        VARIABLE arr : STD_LOGIC_VECTOR(31 DOWNTO 0);
        variable counter : integer := 0;
        variable clock_num : integer := 0;
    BEGIN

        IF (rising_edge(clk) AND counter < 17) THEN

            IF (counter = 0) THEN 
                arr (15 DOWNTO 0) := a;

                arr (31 DOWNTO 16) := bin_literal;

                s <= '0';
                
                counter := counter + 1;

            ELSIF (arr (0) = '0' AND s = '1') THEN
                arr (31 DOWNTO 16) := arr (31 DOWNTO 16) + b;

                s <= arr (0); --Previous value is move down to result

                arr (30 DOWNTO 0) := arr (31 DOWNTO 1);
                
                counter := counter + 1;
                
            ELSIF (arr (0) = '1' AND s = '0') THEN

                arr (31 DOWNTO 16) := arr (31 DOWNTO 16) + NOT b + 1;

                s <= arr (0); --Previous value is move down to result

                arr (30 DOWNTO 0) := arr (31 DOWNTO 1);
                
                counter := counter + 1; 

            ELSE 
--                counter := counter ;
--                while not((counter_var = 0) or (arr(0) = '1' and s = '0') or (s = '1' and arr(0) = '0')) loop 
                while (arr(0) = s) loop 
                    s <= arr (0); --Previous value is move down to result
                    arr (30 DOWNTO 0) := arr (31 DOWNTO 1);
                    counter := counter + 1;
                end loop;
--                counter := counter;
            END IF;

            clock_num := clock_num + 1; --incrementing counter
            clock_sig <= clock_sig + 1;
            c <= arr; --result of multipication
            result <= arr;
            clock_cycle <= clock_num;
               
        END IF;


    END PROCESS;



END Behavioral;