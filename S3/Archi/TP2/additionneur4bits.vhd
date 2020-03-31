LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY add_4b IS
    PORT ( a : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
           b : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
           re : IN STD_LOGIC;
           s : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
           rs : OUT STD_LOGIC);
END ENTITY add_4b;

ARCHITECTURE arc OF full_add1 IS

    SIGNAL r : STD_LOGIC_VECTOR(4 downto 0);
    COMPONENT add_1 IS
        PORT ( a : IN STD_LOGIC;
           b : IN STD_LOGIC;
           re : IN STD_LOGIC;
           s : OUT STD_LOGIC;
           rs : OUT STD_LOGIC);
    END COMPONENT;
    BEGIN
        r(0) <= re;
        additionneurs : FOR i IN 0 TO 3 GENERATE
            addi : add_1b
                PORT MAP (
                    a=>a(i),
                    b=>b(i),
                    re=>r(i),
                    s=>s(i),
                    rs=>r(i+1)
                );
        END GENERATE additionneurs;
        rs <= r(4);
END ARCHITECTURE;a=>a(i),
