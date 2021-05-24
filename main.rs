use std::collections::HashMap;
use paste::paste; // https://crates.io/crates/paste

#[derive(Debug)]
struct Piola<'a> {
    a: HashMap<&'a str, i64>,
    b: HashMap<&'a str, i64>,
    c: HashMap<&'a str, i64>,
    mutable_a: HashMap<&'a str, i64>,
    mutable_b: HashMap<&'a str, i64>,
    mutable_c: HashMap<&'a str, i64>,
}

impl Piola<'_> {
    fn new() -> Piola<'static> {
        return Piola {
            a: HashMap::new(),
            b: HashMap::new(),
            c: HashMap::new(),
            mutable_a: HashMap::new(),
            mutable_b: HashMap::new(),
            mutable_c: HashMap::new(),
        };
    }
}

fn merge_maps<'a>(from: &Piola<'a>, to: &mut Piola<'a>) {
    macro_rules! merge_int {
        ($name:ident) => {
            paste! {
                for (key, value) in &from.[<$name>] {
                    *to.[<mutable_ $name>]
                        .entry(key)
                        .or_insert(0) += value;
                }
            }
        };
    }

    merge_int!(a);
    merge_int!(b);
    merge_int!(c);
}

fn main() {
    let mut piola1 = Piola::new();
    let mut piola2 = Piola::new();

    piola1.a.insert("a", 5);
    piola2.mutable_a.insert("a", 3);
    merge_maps(&piola1, &mut piola2);
    println!("{:?}", piola2.mutable_a.get("a").expect("repiola wacho falló la boludez esta"));
}
