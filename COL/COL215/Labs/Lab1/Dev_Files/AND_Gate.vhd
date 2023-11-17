LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY hw3 IS
    PORT (
        --                CLK : in STD_LOGIC;
        --                RST : in STD_LOGIC;
        Hsync, Vsync : OUT STD_LOGIC;
        vgaRed, vgaGreen, vgaBlue : OUT STD_LOGIC_VECTOR(3 DOWNTO 0));
END hw3;

ARCHITECTURE behavior OF hw3 IS

    COMPONENT dist_mem_gen_2
        PORT (
            a : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
            spo : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)

        );

    END COMPONENT;

    COMPONENT dist_mem_gen_3
        PORT (
            a : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
            spo : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)

        );

    END COMPONENT;

    COMPONENT dist_mem_gen_4

        PORT (

            clk : IN STD_LOGIC;

            a : IN STD_LOGIC_VECTOR(11 DOWNTO 0);

            we : IN STD_LOGIC;

            d : IN STD_LOGIC_VECTOR (19 DOWNTO 0);

            spo : OUT STD_LOGIC_VECTOR(19 DOWNTO 0));

    END COMPONENT;

    -- input

    SIGNAL clock1 : STD_LOGIC := '0';

    SIGNAL clock2 : STD_LOGIC := '0';

    SIGNAL rdaddress : STD_LOGIC_VECTOR(11 DOWNTO 0) := (OTHERS => '0');
    SIGNAL filteraddress : STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0');

    SIGNAL i : INTEGER := 0;
    SIGNAL j : INTEGER := 0;
    SIGNAL k : INTEGER := 0;
    SIGNAL anup : INTEGER := 1;
    SIGNAL new_sig : INTEGER := - 64;

    SIGNAL a1 : INTEGER := 0;
    SIGNAL a2 : INTEGER := 0;
    SIGNAL a3 : INTEGER := 0;
    SIGNAL a4 : INTEGER := 0;
    SIGNAL a5 : INTEGER := 0;
    SIGNAL a6 : INTEGER := 0;
    SIGNAL a7 : INTEGER := 0;
    SIGNAL a8 : INTEGER := 0;
    SIGNAL a9 : INTEGER := 0;
    SIGNAL calc : INTEGER := 0; --a4 has been renamed to calc

    SIGNAL new1 : INTEGER := 0;

    SIGNAL data : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');
    SIGNAL filterdata : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');
    SIGNAL data1 : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL data2 : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL data3 : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL data4 : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL data5 : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL data6 : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL data7 : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL data8 : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL data9 : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');
    CONSTANT clock_period : TIME := 5 ps;

    SIGNAL calculated : STD_LOGIC_VECTOR (19 DOWNTO 0) := (OTHERS => '0'); --data4 has been renamed to calculated
    SIGNAL data_in : STD_LOGIC_VECTOR (7 DOWNTO 0) := (OTHERS => '0');

    SIGNAL wr : STD_LOGIC := '1';

    SIGNAL data_out : STD_LOGIC_VECTOR (19 DOWNTO 0) := (OTHERS => '0');

    SIGNAL clock : STD_LOGIC := '0';

    SIGNAL f0 : INTEGER := 0;
    SIGNAL f1 : INTEGER := 0;
    SIGNAL f2 : INTEGER := 0;
    SIGNAL f3 : INTEGER := 0;
    SIGNAL f4 : INTEGER := 0;
    SIGNAL f5 : INTEGER := 0;
    SIGNAL f6 : INTEGER := 0;
    SIGNAL f7 : INTEGER := 0;
    SIGNAL f8 : INTEGER := 0;
    SIGNAL f9 : INTEGER := 0;

    SIGNAL min : STD_LOGIC_VECTOR (19 DOWNTO 0) := (OTHERS => '0');
    SIGNAL max : STD_LOGIC_VECTOR (19 DOWNTO 0) := (OTHERS => '0');
    SIGNAL difference : INTEGER := 0;
    SIGNAL clk : STD_LOGIC := '0';
    SIGNAL rst : STD_LOGIC := '0';

    SIGNAL normValue : INTEGER := 0;

    SIGNAL clk50 : STD_LOGIC := '0';

    SIGNAL clk25 : STD_LOGIC := '0';

    CONSTANT HD : INTEGER := 639;

    CONSTANT HFP : INTEGER := 16;

    CONSTANT HSP : INTEGER := 96;

    CONSTANT HBP : INTEGER := 48;

    CONSTANT VD : INTEGER := 479;

    CONSTANT VFP : INTEGER := 10;

    CONSTANT VSP : INTEGER := 2;

    CONSTANT VBP : INTEGER := 33;

    SIGNAL hPos : INTEGER := 0;

    SIGNAL vPos : INTEGER := 0;

    SIGNAL startNorm : INTEGER := 0;

    SIGNAL videoOn : STD_LOGIC := '0';

    SIGNAL type1 : STD_LOGIC := '0';

    SIGNAL N : INTEGER := 0;
BEGIN

    uut : dist_mem_gen_2 PORT MAP(

        spo => filterdata,

        a => filteraddress

    );

    uut1 : dist_mem_gen_3 PORT MAP(

        spo => data,

        a => rdaddress

    );

    uut2 : dist_mem_gen_4 PORT MAP(

        clk => clk25,

        d => calculated,

        we => wr,

        spo => data_out,

        a => rdaddress

    );
    clock_process : PROCESS
    BEGIN

        clk <= '0';
        WAIT FOR clock_period/2;
        clk <= '1';
        WAIT FOR clock_period/2;

    END PROCESS;
    clk_div50 : PROCESS (CLK)

    BEGIN

        IF (CLK'event AND CLK = '1') THEN

            clk50 <= NOT clk50;

        END IF;

    END PROCESS;

    clk_div25 : PROCESS (CLK50)

    BEGIN

        IF (CLK50'event AND CLK50 = '1') THEN

            clk25 <= NOT clk25;

        END IF;

    END PROCESS;

    ss1 : PROCESS (CLk25)

    BEGIN

        IF rising_edge(CLK25) THEN

            IF N = 0 THEN

                IF (j < 10) THEN
                    IF (j = 0) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f0 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    ELSIF (j = 1) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f1 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    ELSIF (j = 2) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f4 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    ELSIF (j = 3) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f7 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    ELSIF (j = 4) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f2 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    ELSIF (j = 5) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f5 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    ELSIF (j = 6) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f8 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    ELSIF (j = 7) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f3 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    ELSIF (j = 8) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f6 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    ELSIF (j = 9) THEN
                        filteraddress <= STD_LOGIC_VECTOR(to_unsigned(j, 4));
                        f9 <= to_integer(signed(filterdata));
                        j <= j + 1;
                    END IF;

                END IF;
                IF (j > 9) THEN
                    IF k = 0 THEN
                        IF (new_sig >= 0 AND new_sig < 4096) THEN

                            IF type1 = '0' THEN
                                rdaddress <= STD_LOGIC_VECTOR(to_unsigned(new_sig, 12));
                                type1 <= '1';
                            ELSE
                                a4 <= to_integer(unsigned(data));
                                type1 <= '0';
                                new_sig <= i;
                                k <= 1;
                            END IF;
                        ELSE
                            a4 <= 0;
                            new_sig <= i;
                            k <= 1;
                        END IF;

                    ELSIF k = 1 THEN

                        IF type1 = '0' THEN
                            rdaddress <= STD_LOGIC_VECTOR(to_unsigned(new_sig, 12));
                            type1 <= '1';
                        ELSE
                            a5 <= to_integer(unsigned(data));
                            type1 <= '0';
                            k <= 2;
                            new_sig <= i + 64;
                        END IF;
                    ELSIF k = 2 THEN
                        IF (new_sig >= 0 AND new_sig < 4096) THEN
                            IF type1 = '0' THEN
                                rdaddress <= STD_LOGIC_VECTOR(to_unsigned(new_sig, 12));
                                type1 <= '1';
                            ELSE
                                a6 <= to_integer(unsigned(data));
                                type1 <= '0';
                                new_sig <= i - 65;
                                k <= 3;
                            END IF;
                        ELSE
                            a6 <= 0;
                            new_sig <= i - 65;
                            k <= 3;
                        END IF;

                    ELSIF k = 3 THEN
                        IF (new_sig >= 0 AND new_sig < 4096) THEN
                            IF type1 = '0' THEN
                                rdaddress <= STD_LOGIC_VECTOR(to_unsigned(new_sig, 12));
                                type1 <= '1';
                            ELSE
                                a1 <= to_integer(unsigned(data));
                                type1 <= '0';
                                new_sig <= i - 1;
                                k <= 4;
                            END IF;
                        ELSE
                            a1 <= 0;
                            new_sig <= i - 1;
                            k <= 4;
                        END IF;

                    ELSIF k = 4 THEN
                        IF (new_sig >= 0 AND new_sig < 4096) THEN
                            IF type1 = '0' THEN
                                rdaddress <= STD_LOGIC_VECTOR(to_unsigned(new_sig, 12));
                                type1 <= '1';
                            ELSE
                                a2 <= to_integer(unsigned(data));
                                type1 <= '0';
                                new_sig <= i + 63;
                                k <= 5;
                            END IF;
                        ELSE
                            a2 <= 0;
                            new_sig <= i + 63;
                            k <= 5;
                        END IF;

                    ELSIF k = 5 THEN
                        IF (new_sig >= 0 AND new_sig < 4096) THEN
                            IF type1 = '0' THEN
                                rdaddress <= STD_LOGIC_VECTOR(to_unsigned(new_sig, 12));
                                type1 <= '1';
                            ELSE
                                a3 <= to_integer(unsigned(data));
                                type1 <= '0';
                                new_sig <= i - 63;
                                k <= 6;
                            END IF;
                        ELSE
                            a3 <= 0;
                            new_sig <= i - 63;
                            k <= 6;
                        END IF;

                    ELSIF k = 6 THEN
                        IF (new_sig >= 0 AND new_sig < 4096) THEN
                            IF type1 = '0' THEN
                                rdaddress <= STD_LOGIC_VECTOR(to_unsigned(new_sig, 12));
                                type1 <= '1';
                            ELSE
                                a7 <= to_integer(unsigned(data));
                                type1 <= '0';
                                new_sig <= i + 1;
                                k <= 7;
                            END IF;
                        ELSE
                            a7 <= 0;
                            new_sig <= i + 1;
                            k <= 7;
                        END IF;

                    ELSIF k = 7 THEN
                        IF (new_sig >= 0 AND new_sig < 4096) THEN
                            IF type1 = '0' THEN
                                rdaddress <= STD_LOGIC_VECTOR(to_unsigned(new_sig, 12));
                                type1 <= '1';
                            ELSE
                                a8 <= to_integer(unsigned(data));
                                type1 <= '0';
                                k <= 8;
                                new_sig <= i + 65;
                            END IF;
                        ELSE
                            a8 <= 0;
                            k <= 8;
                            new_sig <= i + 65;
                        END IF;

                    ELSIF k = 8 THEN
                        IF (new_sig >= 0 AND new_sig < 4096) THEN
                            IF type1 = '0' THEN
                                rdaddress <= STD_LOGIC_VECTOR(to_unsigned(new_sig, 12));
                                type1 <= '1';
                            ELSE
                                a9 <= to_integer(unsigned(data));
                                type1 <= '0';
                                k <= 9;
                                new_sig <= new_sig - 128;
                            END IF;
                        ELSE
                            a9 <= 0;
                            k <= 9;
                            new_sig <= new_sig - 128;
                        END IF;

                    END IF;
                    IF k = 9 THEN

                        IF (i MOD 64 = 0) THEN
                            a1 <= 0;
                            a2 <= 0;
                            a3 <= 0;

                        END IF;
                        IF (i MOD 64 = 63) THEN
                            a7 <= 0;
                            a8 <= 0;
                            a9 <= 0;

                        END IF;

                        --                if ( j mod 64 = 63) then

                        --                    a3 <= 0;

                        --                elsif ( j mod 64 = 0) then

                        --                    a1 <= 0;

                        --                end if;

                        --                a4 <= a3 - 2*a2 + a1;
                        k <= k + 1;
                    END IF;
                    IF k = 10 THEN
                        IF type1 = '0' THEN
                            calc <= f1 * a1 + f2 * a2 + f3 * a3 + f4 * a4 + f5 * a5 + f6 * a6 + f7 * a7 + f8 * a8 + f9 * a9;
                            type1 <= '1';

                        ELSE
                            type1 <= '0';
                            IF (to_integer(signed(max)) < calc) THEN
                                max <= STD_LOGIC_VECTOR(to_signed(calc, 20));
                            END IF;

                            IF (to_integer(signed(min)) > calc) THEN
                                min <= STD_LOGIC_VECTOR(to_signed(calc, 20));
                            END IF;

                            --                    if ( calc< 0 ) then

                            --                        calc <= 0;

                            --                    elsif ( calc > 64) then

                            --                        calc <= 64;

                            --                    end if;

                            --                j <= j+1;

                            calculated <= STD_LOGIC_VECTOR(to_signed(calc, 20));

                            --                data2 <= data3;

                            --                data1 <= data2;

                            --                data_in <= data4;

                            i <= i + 1;

                            IF i = 4096 THEN
                                --                            startNorm <= 1;
                                i <= 0;
                                wr <= '0';
                                N <= 1;
                                difference <= to_integer(signed(max)) - to_integer(signed(min));
                            END IF;

                            k <= 0;
                        END IF;
                    END IF;
                END IF;
            ELSIF N = 1 THEN

                IF (i < 4096) THEN

                    IF anup = 1 THEN
                        rdaddress <= STD_LOGIC_VECTOR(to_unsigned(i, 12));
                        anup <= anup + 1;
                    ELSIF anup = 2 THEN
                        normValue <= (to_integer(signed(data_out)) - to_integer(signed(min))) * 255/difference;
                        wr <= '1';
                        anup <= anup + 1;
                    ELSE
                        rdaddress <= STD_LOGIC_VECTOR(to_unsigned(i, 12));
                        calculated <= STD_LOGIC_VECTOR(to_unsigned(normValue, 20));
                        wr <= '0';
                        anup <= 1;
                    END IF;

                END IF;

            ELSE
            END IF;

        END IF;

    END PROCESS;

    --    norm : process(startNorm)
    --    begin
    --        if(startNorm = 1) then
    --            if(i<4096) then
    --                if anup =1 then
    --                    rdaddress <= std_logic_vector(to_unsigned(i,12));
    --                    anup <= anup + 1;
    --                elsif anup = 2 then
    --                    normValue <= (to_integer(signed(data_out)) - to_integer(signed(min)))*255/difference;
    --                    wr <= '1';
    --                    anup <= anup +1;
    --                else
    --                    rdaddress <=std_logic_vector(to_unsigned(i,12));
    --                    calculated <= std_logic_vector(to_unsigned(normValue,20));
    --                    wr <= '0';
    --                    anup <=1;
    --                end if;
    --            end if;
    --        end if;
    --    end process;
    Horizontal_position_counter : PROCESS (clk25, RST)

    BEGIN

        IF (wr = '0') THEN

            IF (RST = '1') THEN

                hpos <= 0;

            ELSIF (clk25'event AND clk25 = '1') THEN

                IF (hPos = HD + HFP + HSP + HBP) THEN

                    hPos <= 0;

                ELSE

                    hPos <= hPos + 1;

                END IF;

            END IF;

        ELSE

            hpos <= 0;

        END IF;

    END PROCESS;

    Vertical_position_counter : PROCESS (clk25, RST, hPos)

    BEGIN

        IF (wr = '0') THEN

            IF (RST = '1') THEN

                vPos <= 0;

            ELSIF (clk25'event AND clk25 = '1') THEN

                IF (hPos = HD + HFP + HSP + HBP) THEN

                    IF (vPos = VD + VFP + VSP + VBP) THEN

                        vPos <= 0;

                    ELSE

                        vPos <= vPos + 1;

                    END IF;

                END IF;

            END IF;

        ELSE

            vPos <= 0;

        END IF;

    END PROCESS;

    Horizonal_Synchronisation : PROCESS (clk25, RST, hPos)

    BEGIN

        IF (wr = '0') THEN

            IF (RST = '1') THEN

                HSYNC <= '0';

            ELSIF (clk25'event AND clk25 = '1') THEN

                IF (hPos <= (HD + HFP) OR (hPos > HD + HFP + HSP)) THEN

                    HSYNC <= '1';

                ELSE

                    HSYNC <= '0';

                END IF;

            END IF;

        ELSE

            HSYNC <= '0';

        END IF;

    END PROCESS;

    Vertical_Synchronisation : PROCESS (clk25, RST, vPos)

    BEGIN

        IF (wr = '0') THEN

            IF (RST = '1') THEN

                VSYNC <= '0';

            ELSIF (clk25'event AND clk25 = '1') THEN

                IF (vPos <= (VD + VFP) OR (vPos > VD + VFP + VSP)) THEN

                    VSYNC <= '1';

                ELSE

                    VSYNC <= '0';

                END IF;

            END IF;

        ELSE

            VSYNC <= '0';

        END IF;

    END PROCESS;

    video_on : PROCESS (clk25, RST, hPos, vPos)

    BEGIN

        IF (RST = '1') THEN

            videoOn <= '0';

        ELSIF (clk25'event AND clk25 = '1') THEN

            IF (hPos <= HD AND vPos <= VD) THEN

                videoOn <= '1';

            ELSE

                videoOn <= '0';

            END IF;

        END IF;

    END PROCESS;

    draw : PROCESS (clk25, RST, hPos, vPos, videoOn)

    BEGIN

        IF (wr = '0') THEN

            IF (RST = '1') THEN

                vgaRed <= "0000";

                vgaBlue <= "0000";

                vgaGreen <= "0000";

            ELSIF (clk25'event AND clk25 = '1') THEN

                IF (videoOn = '1') THEN

                    IF ((hPos >= 0 AND hPos < 64) AND (vPos >= 0 AND vPos < 64)) THEN

                        vgaRed <= data_out(7 DOWNTO 4);
                        vgaBlue <= data_out(7 DOWNTO 4);
                        vgaGreen <= data_out(7 DOWNTO 4);

                    ELSE

                        vgaRed <= "0000";

                        vgaBlue <= "0000";

                        vgaGreen <= "0000";

                    END IF;

                ELSE

                    vgaRed <= "0000";

                    vgaBlue <= "0000";

                    vgaGreen <= "0000";

                END IF;

            END IF;

        ELSE

            vgaRed <= "0000";

            vgaBlue <= "0000";

            vgaGreen <= "0000";

        END IF;

    END PROCESS;

END;