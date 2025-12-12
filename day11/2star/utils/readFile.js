const fs = require('fs');


const initMap = (filePath) => {
    let dane;
    try {
        dane = fs.readFileSync(filePath, 'utf8');
    } catch (error) {
        console.error("nie wczytano pliku");
    }
    const mapa = new Map();
    const linie = dane
        .trim()
        .replaceAll(':', '')
        .split(/\r?\n/);
    const linie2 = linie.map(wiersz => {
        return wiersz.split(/\s+/);
    });


    for (const vals of linie2) {
        const wartosci = vals.slice(1);
        mapa.set(vals[0], wartosci);
    }
    return mapa;
}

const solution = (key, mapa, memo = new Map(), isDac = false, isFft = false) => {
    if (key === "dac") isDac = true;
    if (key === "fft") isFft = true;
    const memoKey = `${key}-${isDac}-${isFft}`;
    if (memo.has(memoKey)) return memo.get(memoKey);
    if (key === "out") return (isDac && isFft) ? 1 : 0;

    let sum = 0;
    const vals = mapa.get(key) || [];
    for (const val of vals) {
        console.log(val);
        sum += solution(val, mapa, memo, isDac, isFft);
    }
    memo.set(memoKey, sum);
    return sum;
}

module.exports = {
    initMap,
    solution
};