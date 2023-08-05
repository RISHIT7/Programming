LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY T11_std_logic_vector IS
END ENTITY;

ARCHITECTURE sim OF T11_std_logic_vector IS

    SIGNAL siv1 : STD_LOGIC_VECTOR (7 DOWNTO 0);
    SIGNAL siv2 : STD_LOGIC_VECTOR (7 DOWNTO 0) := (OTHERS => '0');
    SIGNAL siv3 : STD_LOGIC_VECTOR (7 DOWNTO 0) := (OTHERS => '1'); -- preferred way
    SIGNAL siv4 : STD_LOGIC_VECTOR (7 DOWNTO 0) := x"AA"; -- hexadecimal value
    SIGNAL siv5 : STD_LOGIC_VECTOR (7 DOWNTO 0) := "10101010"; -- binary input 
    SIGNAL siv5 : STD_LOGIC_VECTOR (0 TO 7) := "10101010"; -- indexing is different
    SIGNAL siv6 : STD_LOGIC_VECTOR (7 DOWNTO 0) := "00000001";

BEGIN

    PROCESS IS
    BEGIN

        WAIT FOR 10 ns;

        FOR i IN siv6'left DOWNTO 1 LOOP
            siv6(i) <= siv6(i - 1);
        END LOOP;

        siv6(siv6'right) <= siv6(suv6'left);
    END PROCESS;

END sim;