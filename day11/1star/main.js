const { initMap, solution } = require('./utils/readFile');

const mapa = initMap('input.txt');
// console.log(mapa);
const solution_output = solution("you", mapa);
console.log(solution_output);