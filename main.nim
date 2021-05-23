# uninhm, juancarlospaco
import tables

type Piola = ref object
    boludo: Table[string, int]
    cheto: Table[string, int]
    guita: Table[string, int]
    mutable_boludo: Table[string, int]
    mutable_cheto: Table[string, int]
    mutable_guita: Table[string, int]


proc merge_maps(phrom, to: Piola) =
    template merge_int(name) =
        for k, v in phrom.`name`:
            to.` mutable _ name`[k] += v
    
    merge_int boludo
    merge_int cheto
    merge_int guita


var piola1 = Piola()
var piola2 = Piola()

piola1.mutable_boludo["a"] = 3
piola2.mutable_boludo["a"] = 5
merge_maps(piola1, piola2)
echo piola2.mutable_boludo["a"]
