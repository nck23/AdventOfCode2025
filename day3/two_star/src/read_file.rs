use std::fs;

pub fn wczytaj_plik(file_path: &str) -> Vec<String>{
    let zawartosc = fs::read_to_string(file_path)
    .expect("Nie udalo sie wczytac");
    let linie: Vec<String> = zawartosc.lines()
        .map(|s| s.to_string())
        .collect();
    linie
}


pub fn solution(all_lines: Vec<String>) -> i64 {
    let mut sum: i64 = 0;
    
    for line in &all_lines{
        // println!("{}", line);
        let bytes = line.as_bytes();
        if bytes.is_empty() {continue;} 
        let mut tab_i: [usize; 12] = [999; 12];
        let mut tab_max: [i32; 12] = [0; 12];
        for j in 0..12 {
            if j == 0 {
                let aktualny_koniec = bytes.len() - 11;
                for i in 0..aktualny_koniec {
                    let value: i32 = (bytes[i] - b'0') as i32;
                    if value > tab_max[j] && i != aktualny_koniec && tab_i[j] != i { // tutaj sprawdzic czy -12?
                        tab_max[j] = value;
                        tab_i[j] = i;
                    }
                }
                // print!("{} ", tab_max[j]);
            } else {
                let aktualny_koniec = bytes.len() - (11 - j);
                for i in tab_i[j-1]+1..aktualny_koniec {
                    let value: i32 = (bytes[i] - b'0') as i32;
                    if value > tab_max[j] && i != aktualny_koniec && tab_i[j] != i { // tutaj sprawdzic czy -12?
                        tab_max[j] = value;
                        tab_i[j] = i;
                    }
                }
                // print!("{} ", tab_max[j]);
            }
        }
        let mut liczba_duza: i64 = 0;
        for &cyfra in &tab_max {
            liczba_duza = liczba_duza * 10 + (cyfra as i64);
        }
        sum += liczba_duza;
        // println!();
        
    }
    
    sum
}