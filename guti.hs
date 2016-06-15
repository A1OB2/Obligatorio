arbol_b::ArbolTableaux
arbol_b = [[(Ex "x" (Bc And (A "P" [V "x"]) (A "Q" [V "x"]))), (Neg(Bc And (Ex "x" (A "P" [V "x"])) (Ex "x" (A "Q" [V "x"])) ))]]

demostracion_b::Demostracion
demostracion_b = [(Exis "a", 0), (Conj, 0), (Disy, 2), (Univer "a", 2), (Univer "a", 2)]