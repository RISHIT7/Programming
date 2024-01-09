library IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.numeric_std.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Multiplier_top_level is
end Multiplier_top_level;

architecture Behavioral of Multiplier_top_level is
    signal a : std_logic_vector(15 downto 0) := "0100110111101011";
    signal b : std_logic_vector(15 downto 0) := "0001000101000000";
    signal c_a : std_logic_vector(31 downto 0) := (others => '0');
    signal c_b : std_logic_vector(31 downto 0) := (others => '0');
    signal clock_cycles_a : integer := 0;
    signal clock_cycles_b : integer := 0;
    signal clk : std_logic := '0';
    constant clock_period : time := 10ns;
    
    component Multiplier
        Port (
            a: in std_logic_vector(15 downto 0);
            b: in std_logic_vector(15 downto 0);
            clk : in std_logic;
            c: out std_logic_vector(31 downto 0);
            clock_cycle : out integer
        );
    end component;
    
    component Booths_Multiplication
        Port (
            a: in std_logic_vector(15 downto 0);
            b: in std_logic_vector(15 downto 0);
            clk : in std_logic;
            c: out std_logic_vector(31 downto 0);
            clock_cycle : out integer
        );
    end component;

    begin
    
        process
        begin
            wait for clock_period/2;
            clk <= not clk;
        end process;
    
        MUL_a : Multiplier port map (a, b, clk, c_a, clock_cycles_a);
        MUL_b : Booths_Multiplication port map (a, b, clk ,c_b, clock_cycles_b);
end Behavioral;
