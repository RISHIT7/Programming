LIBRARY ieee;
USE ieee.STD_LOGIC_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY T12_SignedAndUnsigned IS
END ENTITY;

ARCHITECTURE sim OF T12_SignedAndUnsigned IS

    SIGNAL UnsCount : unsigned(7 DOWNTO 0) := (OTHERS => '0'); -- interpreted as numbers
    SIGNAL SigCount : signed(7 DOWNTO 0) := (OTHERS => '0');
    SIGNAL Unst4 : unsigned(3 DOWNTO 0) := "1000";
    SIGNAL Sig4 : signed(3 DOWNTO 0) := "1000";


BEGIN;

    PROCESS IS
    BEGIN
        WAIT FOR 10 ns;

        -- wrapping counter;
        UnsCount <= UnsCount + 1;
        SigCount <= SigCount + 1;

        -- adding signals;
        Uns 
    END PROCESS;

END sim;