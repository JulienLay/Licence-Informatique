LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY test IS
END ENTITY;

ARCHITECTURE arc OF test IS

    SIGNAL clk, rst, wr : STD_LOGIC:='0';
    SIGNAL dataIn : STD_LOGIC_VECTOR(7 DOWNTO 0):="11111111";
    SIGNAL dataOut : STD_LOGIC_VECTOR(7 DOWNTO 0):="00000000";

BEGIN

    comp : ENTITY WORK.registre_8b PORT MAP (clk, rst, wr, dataIn, dataOut);

    PROCESS
      TYPE TableDeVerite IS ARRAY (0 TO 7) OF STD_LOGIC_VECTOR(2 DOWNTO 0);
      constant TdV : TableDeVerite := ("000","001","010","011","100","101","110","111");

      BEGIN
          FOR I IN TDV'RANGE LOOP
              clk <= TdV(I)(0);
              rst <= TdV(I)(1);
              wr  <= TdV(I)(2);
              WAIT FOR 5 ns;
          END LOOP;
          WAIT;
      END PROCESS;
  END ARCHITECTURE;
