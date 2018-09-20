var tach = new RadialGauge({
    renderTo: 'tach',
    width: 600,
    height: 600,
    units: "RPM x1000",
    title: "Tach",
    minValue: 0,
    maxValue: 6000,
    majorTicks: [
        0,
        1,
        2,
        3,
        4,
        5,
        6
    ],
    minorTicks: 1,
    strokeTicks: true,
    highlights: [
        {
            "from": 4500,
            "to": 6000,
            "color": "rgba(255, 0, 0, .3)"
        }
    ],
    ticksAngle: 225,
    startAngle: 67.5,
    colorMajorTicks: "#ddd",
    colorMinorTicks: "#ddd",
    colorTitle: "#eee",
    colorUnits: "#ccc",
    colorNumbers: "#eee",
    colorPlate: "#222",
    borderShadowWidth: 0,
    borders: true,
    needleType: "arrow",
    needleWidth: 2,
    needleCircleSize: 7,
    needleCircleOuter: true,
    needleCircleInner: false,
    animationDuration: 250,
    animationRule: "linear",
    colorBorderOuter: "#333",
    colorBorderOuterEnd: "#111",
    colorBorderMiddle: "#222",
    colorBorderMiddleEnd: "#111",
    colorBorderInner: "#111",
    colorBorderInnerEnd: "#333",
    colorNeedleShadowDown: "#333",
    colorNeedleCircleOuter: "#333",
    colorNeedleCircleOuterEnd: "#111",
    colorNeedleCircleInner: "#111",
    colorNeedleCircleInnerEnd: "#222",
    valueBoxBorderRadius: 0,
    colorValueBoxRect: "#222",
    colorValueBoxRectEnd: "#333"
}).draw();

var temp = new RadialGauge({
    renderTo: 'temp',
    width: 300,
    height: 300,
    units: "°F",
    title: "Temp",
    minValue: 140,
    maxValue: 280,
    majorTicks: [
        140,
        195,
        280
    ],
    minorTicks: 3,
    strokeTicks: true,
    highlights: [
        {
            "from": 240,
            "to": 280,
            "color": "rgba(255, 0, 0, .3)"
        }
    ],
    ticksAngle: 180,
    startAngle: 90,
    colorMajorTicks: "#ddd",
    colorMinorTicks: "#ddd",
    colorTitle: "#eee",
    colorUnits: "#ccc",
    colorNumbers: "#eee",
    colorPlate: "#222",
    borderShadowWidth: 0,
    borders: true,
    needleType: "arrow",
    needleWidth: 2,
    needleCircleSize: 7,
    needleCircleOuter: true,
    needleCircleInner: false,
    animationDuration: 250,
    animationRule: "linear",
    colorBorderOuter: "#333",
    colorBorderOuterEnd: "#111",
    colorBorderMiddle: "#222",
    colorBorderMiddleEnd: "#111",
    colorBorderInner: "#111",
    colorBorderInnerEnd: "#333",
    colorNeedleShadowDown: "#333",
    colorNeedleCircleOuter: "#333",
    colorNeedleCircleOuterEnd: "#111",
    colorNeedleCircleInner: "#111",
    colorNeedleCircleInnerEnd: "#222",
    valueBoxBorderRadius: 0,
    colorValueBoxRect: "#222",
    colorValueBoxRectEnd: "#333"
}).draw();

var oil = new RadialGauge({
    renderTo: 'oil',
    width: 300,
    height: 300,
    units: "psi",
    title: "Oil",
    minValue: 0,
    maxValue: 100,
    majorTicks: [
        0,
        50,
        100
    ],
    minorTicks: 3,
    strokeTicks: true,
    highlights: [
    ],
    ticksAngle: 180,
    startAngle: 90,
    colorMajorTicks: "#ddd",
    colorMinorTicks: "#ddd",
    colorTitle: "#eee",
    colorUnits: "#ccc",
    colorNumbers: "#eee",
    colorPlate: "#222",
    borderShadowWidth: 0,
    borders: true,
    needleType: "arrow",
    needleWidth: 2,
    needleCircleSize: 7,
    needleCircleOuter: true,
    needleCircleInner: false,
    animationDuration: 250,
    animationRule: "linear",
    colorBorderOuter: "#333",
    colorBorderOuterEnd: "#111",
    colorBorderMiddle: "#222",
    colorBorderMiddleEnd: "#111",
    colorBorderInner: "#111",
    colorBorderInnerEnd: "#333",
    colorNeedleShadowDown: "#333",
    colorNeedleCircleOuter: "#333",
    colorNeedleCircleOuterEnd: "#111",
    colorNeedleCircleInner: "#111",
    colorNeedleCircleInnerEnd: "#222",
    valueBoxBorderRadius: 0,
    colorValueBoxRect: "#222",
    colorValueBoxRectEnd: "#333"
}).draw();

var volt = new RadialGauge({
    renderTo: 'volt',
    width: 300,
    height: 300,
    units: "Volts",
    title: "",
    minValue: 8,
    maxValue: 18,
    majorTicks: [
        8,
        13,
        18
    ],
    minorTicks: 4,
    strokeTicks: true,
    highlights: [
        {
            "from": 8,
            "to": 10,
            "color": "rgba(255, 0, 0, .3)"
        },
        {
            "from": 16,
            "to": 18,
            "color": "rgba(255, 0, 0, .3)"
        }        
    ],
    ticksAngle: 180,
    startAngle: 90,
    colorMajorTicks: "#ddd",
    colorMinorTicks: "#ddd",
    colorTitle: "#eee",
    colorUnits: "#ccc",
    colorNumbers: "#eee",
    colorPlate: "#222",
    borderShadowWidth: 0,
    borders: true,
    needleType: "arrow",
    needleWidth: 2,
    needleCircleSize: 7,
    needleCircleOuter: true,
    needleCircleInner: false,
    animationDuration: 250,
    animationRule: "linear",
    colorBorderOuter: "#333",
    colorBorderOuterEnd: "#111",
    colorBorderMiddle: "#222",
    colorBorderMiddleEnd: "#111",
    colorBorderInner: "#111",
    colorBorderInnerEnd: "#333",
    colorNeedleShadowDown: "#333",
    colorNeedleCircleOuter: "#333",
    colorNeedleCircleOuterEnd: "#111",
    colorNeedleCircleInner: "#111",
    colorNeedleCircleInnerEnd: "#222",
    valueBoxBorderRadius: 0,
    colorValueBoxRect: "#222",
    colorValueBoxRectEnd: "#333"
}).draw();

(function update() {
    $.ajax({
        type : 'GET',
        url : 'http://localhost:5000/',
        crossDomain: true,
        dataType: 'jsonp',
        success : function(data){
            var readings = data
            tach.value = readings["tach"]
            temp.value = readings["temp"]
            oil.value = readings["oil"]
            volt.value = readings["volt"]
        }
                            // pass existing options
    }).then(function() {           // on completion, restart
       setTimeout(update, 1000);  // function refers to itself
    });
})();   