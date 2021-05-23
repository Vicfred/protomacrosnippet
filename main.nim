# uninhm
import tables

type Piola = ref object
    mutable_aboludo: Table[string, int]
    mutable_acheto: Table[string, int]
    mutable_aguita: Table[string, int]


proc merge_maps(phrom, to: Piola) =
    template merge_int(name) =
        for k, v in phrom.`mutable_a name`:
            to.`mutable_a name`[k] += v
    
    merge_int boludo
    merge_int cheto
    merge_int guita


var piola1 = Piola()
var piola2 = Piola()

piola1.mutable_aboludo["a"] = 3
piola2.mutable_aboludo["a"] = 5
merge_maps(piola1, piola2)
echo piola2.mutable_aboludo["a"]

