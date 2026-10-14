**CONSULTAS**

##GENERAL
los ctontroles debemos hacerlos desde el MAIN o en el TDA??????????????????????????????????

##Paciente
consultar cantidad de espacios en los strings EJ: Nombre[70]
validar tambien datos de paciente en el tda? ya que solo en el tda fecha dice sobre operaciones y restricciones. p/ el resto, hacemos las valdiaciones en el main? o tambien en el tda

##fecha

"consultar sobre el anio (se hace get y set aunque no se vaya a modificar?)"
las validaciones de fecha se hacen en el tda? por ej en el dia deberiamos validar la cantidad de dias segun el mes o solo como dice en el enunciado 
Enunciado explicito:  
Retornar cada uno de los campos por separado, retornar fecha completa, cargar fecha completa.??????


##TURNOS
PREGUNTAR SOBRE set_FechaTurno y controles de Lun a Vie 
PREGUNTAR SOBRE get_FechaTurno

**DECISIONES SOBRE LA MARCHA**
typedef se escribe con mayuscula al principio. Por ej: Paciente var
funciones para setter/getters/init (camelCase) -> init_Type
funciones en general (camelCase) -> cargarHora
variables en minuscula (pascal_case) -> hora_turno