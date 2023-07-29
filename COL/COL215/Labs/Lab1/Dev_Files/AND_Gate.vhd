LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Defining the entity, and the input and ouput ports of that entity
ENTITY AND_Gate IS
    PORT (
        a : IN STD_LOGIC;
        b : IN STD_LOGIC;
        c : OUT STD_LOGIC;
    );
END AND_Gate;

-- Defining the architecture of that entity
ARCHITECTURE sim OF AND_Gate IS

BEGIN
    c <= a AND b; -- assiging the valye a and b to c, all these are initialized as signals, hence we use "<=" rather than ":="
END ARCHITECTURE;