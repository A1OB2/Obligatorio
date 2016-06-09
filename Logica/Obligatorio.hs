module VerificdorTableaux where 
--{Nombre1:NumeroEstudiante1}
--{Nombre2:NumeroEstudiante2}

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
appConjuntiva = undefined

appDisyuntiva :: Form  -> (Form, Form)
appDisyuntiva = undefined

appExist::Simbolo -> Form -> Form 
appExist = undefined

appUniversal::Simbolo -> Form -> (Form, Form)
appUniversal = undefined

esNuevaConst:: Simbolo -> Rama -> Bool
esNuevaConst = undefined

hayContradiccion::Rama -> Bool
hayContradiccion = undefined

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
arbol_e = undefined

demostracion_e::Demostracion
demostracion_e = undefined

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