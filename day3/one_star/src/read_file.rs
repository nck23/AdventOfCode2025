use std::fs;

pub fn wczytaj_plik(file_path: &str) -> Vec<String>{
    let zawartosc = fs::read_to_string(file_path)
    .expect("Nie udalo sie wczytac");
    let linie: Vec<String> = zawartosc.lines()
        .map(|s| s.to_string())
        .collect();


    linie
}


pub fn solution(all_lines: Vec<String>) -> i32 {
    let mut sum = 0;

    for line in &all_lines{
        let bytes = line.as_bytes();
        if bytes.is_empty() {continue;}

        let mut max_1: i32 = 0;
        let mut max_i: usize = 99999999;

        for i in 0..bytes.len() {
            let value: i32 = (bytes[i] - b'0') as i32;
            if value > max_1 && i != bytes.len() - 1 && max_i != i {
                max_1 = value;
                max_i = i;
            }
        }
        let mut max_2: i32 = 0;
        // let mut max_j = 0;
        for j in max_i+1..line.len() {
            let value: i32 = (bytes[j] - b'0') as i32;
            if value > max_2 {
                max_2 = value;
                // max_j = j;
            }
        }
        // println!("{}", max_1*10 + max_2);
        sum += (max_1 as i32)*10 + (max_2 as i32);
    }

    sum
}