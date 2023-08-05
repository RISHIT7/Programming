LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY T15_PortMappingTb IS
END T15_PortMappingTb;

ARCHITECTURE sim OF T15_PortMappingTb IS

    SIGNAL Sig1 : unsigned (7 DOWNTO 0) := x"AA";
    SIGNAL Sig2 : unsigned (7 DOWNTO 0) := x"BB";
    SIGNAL Sig3 : unsigned (7 DOWNTO 0) := x"CC";
    SIGNAL Sig4 : unsigned (7 DOWNTO 0) := x"DD";

    SIGNAL Sel : unsigned (7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL Outp : unsigned (7 DOWNTO 0);

BEGIN
    -- An Instance of the Module
    i_Mux1 : ENTITY work.T15_PortMapping(rtl) PORT MAP(
        Sel => Sel,
        Sig1 => Sig1;
        Sig2 => Sig2;
        Sig3 => Sig3;
        Sig4 => Sig4;
        Outp => Outp;
        );

    -- Testbench Process
    PROCESS IS
    BEGIN
        WAIT FOR 10 ns;
        Sel <= Sel + 1;
        WAIT FOR 10 ns;
        Sel <= Sel + 1;
        WAIT FOR 10 ns;
        Sel <= Sel + 1;
        WAIT FOR 10 ns;
        Sel <= Sel + 1;
        WAIT FOR 10 ns;
        Sel <= Sel + 1;
        WAIT FOR 10 ns;
        Sel <= "UU";
    END PROCESS;
END ARCHITECTURE;