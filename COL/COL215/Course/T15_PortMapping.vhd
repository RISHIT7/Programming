LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- makes the variables global to the other files
ENTITY T15_PortMapping IS
    PORT (
        -- inputs
        Sig1 : IN unsigned (7 DOWNTO 0);
        Sig2 : IN unsigned (7 DOWNTO 0);
        Sig3 : IN unsigned (7 DOWNTO 0);
        Sig4 : IN unsigned (7 DOWNTO 0);

        Sel : IN unsigned (1 DOWNTO 0);

        -- outputs
        Outp : OUT unsigned (7 DOWNTO 0);
    );
END T15_PortMapping;

-- register transfer level == rtl
ARCHITECTURE rtl OF T15_PortMapping IS

BEGIN

    PROCESS (Sel, Sig1, Sig2, Sig3, Sig4) IS
    BEGIN

        CASE Sel IS
            WHEN "00" =>
                Outp <= Sig1;
            WHEN "01" =>
                Outp <= Sig2;
            WHEN "10" =>
                Outp <= Sig3;
            WHEN "11" =>
                Outp <= Sig4;
            WHEN OTHERS =>
                Outp <= (OTHERS => 'X');
        END CASE;
    END PROCESS;
END ARCHITECTURE;