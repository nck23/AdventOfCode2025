mod read_file;


fn main() {
    let file_path = "assets/input.txt";
    let all_lines = read_file::wczytaj_plik(file_path);

    let output = read_file::solution(all_lines);
    println!("{}", output);
}
