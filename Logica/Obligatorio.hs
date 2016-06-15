module VerificdorTableaux where 
--{Bruno Vezoli:201150}
--{Matías Gutierrez:200244}

data Form = A Simbolo [Term] | Neg Form | Bc BinCon Form Form | All Var Form | Ex Var Form 
		deriving (Eq, Show)
data Term = V Var | C Simbolo | F Simbolo [Term]
		deriving (Eq, Show)
type Var = String
type Simbolo = String

data BinCon = And | Or | Impl
		deriving (Eq, Show)

type Rama = [Form]

type ArbolTableaux = [Rama]

data Regla = Conj | Disy | Exis Simbolo | Univer Simbolo

type Demostracion = [(Regla, Int)]

esDemostracionValida::ArbolTableaux -> Demostracion -> Bool
esDemostracionValida a d = case efecturaDemostracion a d of {
	([],[]) -> True;
	_ -> False
}

efecturaDemostracion::ArbolTableaux -> Demostracion -> (ArbolTableaux, Demostracion)
efecturaDemostracion = \a lst -> case lst of{
	[] -> (a, []);
	(x:xs) -> case verificarContradiccion (aplicarRegla (head a) x) of {
		[] -> efecturaDemostracion (tail a) xs ;
	l -> efecturaDemostracion ((l) ++ (tail a)) xs
	}
}

aplicarRegla::Rama -> (Regla, Int) -> ArbolTableaux
aplicarRegla = \fs reg -> case reg of {
	(Conj, i) -> [(take i fs) ++ (appConjuntiva (fs !! i)) ++ (drop (i+1) fs)];
	(Disy, i) -> case appDisyuntiva (fs !! i) of {
				(disIzq, disDer) -> [((take i fs) ++ [disIzq] ++ (drop (i+1) fs)), ((take i fs) ++ [disDer] ++ (drop (i+1) fs))]
	};
	(Exis n, i) -> case esNuevaConst n fs of {
				True -> [(take i fs) ++ [appExist n (fs !! i)] ++ (drop (i+1) fs)];
				False -> error "Mal aplicada la regla existencial, no se puede instanciar en una constante que no sea nueva."
		};
	(Univer n, i) -> case appUniversal n (fs !! i) of {
		(instancia, universal) -> [(take i fs) ++ [instancia] ++ (drop (i+1) fs) ++ [universal]]
	}
}

verificarContradiccion::ArbolTableaux -> ArbolTableaux
verificarContradiccion ls = filter (\m -> not (hayContradiccion m)) ls

--Ejercicio 3:

appConjuntiva ::Form  -> [Form]
appConjuntiva = \f -> case f of{
	Neg a -> case a of{
		Neg b -> [b];
		Bc bc b c -> case bc of{
			Impl-> [b,Neg(c)];
			Or-> [Neg(b),Neg(c)]
		}
	};
	Bc bc a b -> case bc of{
		And -> [a,b];
	};
	_ -> error "No hay regla conjuntiva para eso!!!!"

}

appDisyuntiva :: Form  -> (Form, Form)
appDisyuntiva = \f -> case f of{
	Neg a -> case a of{
		Bc bc b c -> case bc of{
			And-> (Neg(b),Neg(c))
		}
	};
	Bc bc a b -> case bc of{
		Impl-> (Neg(a),b);
		Or -> (a,b);
	};
	_ -> error "No hay regla disyuntiva para eso!!!!"

}

appExist::Simbolo -> Form -> Form 
appExist = \ s f -> case f of{
	Ex v f -> sustAll f v s;
	Neg(All v f) ->Neg(sustAll f v s);
	_ -> error "No hay regla existencial para eso!!!!"
}

appUniversal::Simbolo -> Form -> (Form, Form)
appUniversal = \ s f -> case f of{
	Neg(Ex v f) ->(Neg(sustAll f v s),Neg(Ex v f));--Ver si hay que cambiar de lado
	All v f -> (sustAll f v s,All v f);
	_ -> error "No hay regla universal para eso!!!!"
}

esNuevaConst:: Simbolo -> Rama -> Bool
esNuevaConst s rama=not (or (map (estaEnForm s) rama))

hayContradiccion::Rama -> Bool
hayContradiccion = \r -> case r of{
	[]->False;
	x:xs-> (contradice x xs) || hayContradiccion(xs)
}

--Ejercicio 5:

--a)
arbol_a::ArbolTableaux
arbol_a = undefined

demostracion_a::Demostracion
demostracion_a = undefined

--b)
arbol_b::ArbolTableaux
arbol_b = undefined

demostracion_b::Demostracion
demostracion_b = undefined

--c)
arbol_c::ArbolTableaux
arbol_c = undefined

demostracion_c::Demostracion
demostracion_c = undefined

--d)
arbol_d::ArbolTableaux
arbol_d = undefined

demostracion_d::Demostracion
demostracion_d = undefined

--e)
arbol_e::ArbolTableaux
arbol_e = [[(All "x"(All "y"(Bc Impl (A "R" [V "x",V "y"])(Neg (A "R" [V "y",V "x"]))))),(Neg(All "x"(Neg (A "R" [V "x",V "x"]))))]]

demostracion_e::Demostracion
demostracion_e = [(Exis "a",1),(Conj,1),(Univer "a",0),(Univer "a",0),(Disy,0)]

--f)
arbol_f::ArbolTableaux
arbol_f = undefined

demostracion_f::Demostracion
demostracion_f = undefined

--g)
arbol_g::ArbolTableaux
arbol_g = undefined

demostracion_g::Demostracion
demostracion_g = undefined

--Auxiliares
sustAll::Form -> Var -> Simbolo -> Form
sustAll = \ f v s -> case f of{
	A sim zs -> A sim (map (sustEnTerm s v)  zs);
	Neg f1-> Neg (sustAll f1 v s); 
	Bc bc f1 f2 -> Bc bc (sustAll f1 v s) (sustAll f2 v s);
	All v1 f1-> All v1 (sustAll f1 v s);
	Ex v1 f1 -> Ex v1 (sustAll f1 v s)
}


sustEnTerm::Simbolo -> Var-> Term-> Term
sustEnTerm= \s v t -> case t of{
	V var -> case  v == var of{
		True-> C s;
		False-> V var
	};
	C simbolo -> C simbolo;
	F simbolo ts ->F simbolo (map (sustEnTerm s v) ts)
}

estaEnForm:: Simbolo -> Form -> Bool
estaEnForm= \ s f -> case f of{
	A sim zs -> or (map (estaEnTerm s)  zs);
	Neg f1-> (estaEnForm s f1); 
	Bc bc f1 f2 -> (estaEnForm  s f1) || (estaEnForm s f2);
	All v1 f1-> (estaEnForm  s f1);
	Ex v1 f1 -> (estaEnForm  s f1)
}

estaEnTerm::Simbolo -> Term -> Bool
estaEnTerm= \ s t -> case t of{
	V var -> False;
	C simbolo -> simbolo == s;
	F simbolo ts ->or (map (estaEnTerm s) ts);
}

contradice::Form->[Form]->Bool
contradice= \ f fs -> case fs of{
	[]->False;
	x:xs -> x==Neg(f) || Neg(x)==f || (contradice f xs)
}

--DATOS DE PRUEBA
f1::Form
f1=Bc (And) (Neg(Neg(A "S" [V "a",V "b"]))) (Bc And (A "S2" [V "a",V "b"]) (A "S2" [V "a",V "c"]))
f2::Form
f2 = Ex "x" (Bc And (A "P" [V "x"]) (A "Q" [V "x"]) )
f3::Form
f3 = All "x" (Bc And (A "P" [V "x"]) (A "Q" [V "x"]) )
f4::Form
f4= All "x" (Bc And (A "P" [C "c"]) (A "Q" [C "a"]) )
f5::Form
f5= Neg(Neg(Neg(A "P" [V "x"])))
f6::Form
f6= Neg(Neg(A "P" [V "x"]))
f7::Form
f7=All "x" (Bc And (A "P" [V "x"])(A "Q" [V "x"]) )
f8::Form
f8=Ex "x" (Bc And (A "P" [V "x"])(A "Q" [V "x"]) )
