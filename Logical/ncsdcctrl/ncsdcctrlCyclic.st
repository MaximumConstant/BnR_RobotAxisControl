
PROGRAM _CYCLIC
        
(* ### BEGIN gAxis01 ### *)
        
(* life counter emulation of digital inputs *)
        gAxis01_DiDoIf.iLifeCntReference := gAxis01_DiDoIf.iLifeCntReference + 1;
        gAxis01_DiDoIf.iLifeCntNegHwEnd  := gAxis01_DiDoIf.iLifeCntNegHwEnd  + 1;
        gAxis01_DiDoIf.iLifeCntPosHwEnd  := gAxis01_DiDoIf.iLifeCntPosHwEnd  + 1;
        
(* ### END gAxis01 ### *)

END_PROGRAM

