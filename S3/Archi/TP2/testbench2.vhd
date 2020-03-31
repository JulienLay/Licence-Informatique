LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY test4 IS
END ENTITY;

ARCHITECTURE arc OF test4 IS
    
    SIGNAL a, b, c, S, RS : STD_LOGIC := '0';
    
BEGIN 
    fdd_tp2add4 : ENTITY WORK.add4 PORT MAP (a, b, c, S, RS);
    
    PROCESS
        TYPE TableDeVerite IS ARRAY (0 TO 15) OF STD_LOGIC_VECTOR(3 DOWNTO 0);
        constant TdV : TableDeVerite := ("0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111");
        
    BEGIN 
        FOR I IN TDV'RANGE LOOP
            a <= TdV(I)(2);
            b <= TdV(I)(1);
            c <= TdV(I)(0);
            WAIT FOR 5 ns;
        END LOOP;
        WAIT;
    END PROCESS;
END ARCHITECTURE;
