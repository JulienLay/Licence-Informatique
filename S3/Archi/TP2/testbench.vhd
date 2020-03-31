LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY test IS
END ENTITY;

ARCHITECTURE arc OF test IS
    
    SIGNAL a, b, c, S, R : STD_LOGIC := '0';
    
BEGIN 

    df_full_add1 : ENTITY WORK.full_add1 PORT MAP (a, b, c, S, R);
    a <= '0', '1' AFTER 10 ns, '0' AFTER 20 ns, '1' AFTER 30 ns, '0' AFTER 40 ns, '1' AFTER 50 ns, '0' AFTER 60 ns, '1' AFTER 70 ns, '0' AFTER 80 ns;
    b <= '0', '1' AFTER 20 ns, '0' AFTER 40 ns, '1' AFTER 60 ns;
    c <= '0', '1' AFTER 40 ns, '0' AFTER 80 ns;
END ARCHITECTURE;
