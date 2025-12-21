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

const solution = (key, mapa, memo = new Map()) => {
    if (memo.has(key)) {
        return memo.get(key);
    }
    if (key === "out") {
        return 1;
    }
    let sum = 0;
    const vals = mapa.get(key);
    for (const val of vals) {
        console.log(val)
        sum += solution(val, mapa, memo);
    }
    memo.set(key, sum);
    return sum;

}

module.exports = {
    initMap,
    solution
};