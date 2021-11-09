#ifndef _Catphan_120kV_1mAs_Focus_S_PGA6_Binning2_hpp_
#define _Catphan_120kV_1mAs_Focus_S_PGA6_Binning2_hpp_

class Catphan_Focus_S_PGA6_Binning2 {
public:
    Catphan_Focus_S_PGA6_Binning2() {

    }
    float* get_kval()
    {
        return K_val;
    }
    double* get_dis()
    {
        return dis;
    }

    float* get_ct_val()
    {
        return ct_val;
    }

    float* get_Hu_val()
    {
        return Hu_val;
    }
    int get_indexLength()
    {
        return indexLength;
    }
private:
    int indexLength = 441;
    float K_val[441] = { 8799.300719974477, 8806.562572079518, 8813.805921443789, 8821.030738801324, 8828.236995475147, 8835.42466337874, 8842.593715017507, 8849.744123490176, 8856.875862490206, 8863.988906307135, 8871.083229827918, 8878.158808538221, 8885.2156185237, 8892.253636471241, 8899.272839670175, 8906.273206013451, 8913.254713998806, 8920.217342729879, 8927.161071917302, 8934.085881879775, 8940.991753545095, 8947.878668451158, 8954.746608746944, 8961.59555719345, 8968.425497164617, 8975.236412648215, 8982.028288246695, 8988.801109178015, 8995.554861276441, 9002.289530993321, 9009.00510539781, 9015.70157217758, 9022.378919639512, 9029.037136710329, 9035.676212937227, 9042.296138488458, 9048.896904153893, 9055.478501345557, 9062.04092209812, 9068.584159069385, 9075.10820554072, 9081.613055417469, 9088.098703229352, 9094.565144130804, 9101.01237390131, 9107.44038894571, 9113.849186294447, 9120.238763603827, 9126.609119156223, 9132.960251860251, 9139.292161250938, 9145.604847489834, 9151.898311365116, 9158.172554291654, 9164.427578311057, 9170.663386091677, 9176.8799809286, 9183.077366743599, 9189.25554808506, 9195.414530127895, 9201.554318673398, 9207.674920149102, 9213.7763416086, 9219.858590731325, 9225.921675822323, 9231.965605811987, 9237.990390255767, 9243.996039333857, 9249.982563850848, 9255.949975235362, 9261.898285539646, 9267.827507439168, 9273.737654232154, 9279.628739839121, 9285.500778802376, 9291.353786285488, 9297.187778072745, 9303.00277056857, 9308.79878079692, 9314.575826400673, 9320.33392564096, 9326.073097396498, 9331.793361162898, 9337.494737051924, 9343.17724579076, 9348.84090872123, 9354.48574779901, 9360.111785592799, 9365.719045283482, 9371.307550663265, 9376.877326134787, 9382.428396710206, 9387.960788010265, 9393.474526263337, 9398.969638304448, 9404.446151574277, 9409.904094118121, 9415.343494584873, 9420.764382225938, 9426.166786894159, 9431.5507390427, 9436.916269723917, 9442.263410588228, 9447.592193882914, 9452.902652450957, 9458.194819729813, 9463.46872975019, 9468.7244171348, 9473.961917097085, 9479.18126543995, 9484.382498554425, 9489.56565341837, 9494.73076759512, 9499.877879232125, 9505.00702705957, 9510.118250388989, 9515.211589111837, 9520.287083698075, 9525.344775194702, 9530.384705224318, 9535.406915983618, 9540.411450241907, 9545.398351339587, 9550.367663186627, 9555.319430261017, 9560.253697607217, 9565.170510834563, 9570.069916115703, 9574.951960184972, 9579.81669033679, 9584.664154424021, 9589.494400856327, 9594.307478598512, 9599.103437168853, 9603.882326637406, 9608.644197624315, 9613.389101298093, 9618.117089373913, 9622.828214111858, 9627.522528315183, 9632.200085328557, 9636.860939036287, 9641.505143860551, 9646.132754759588, 9650.743827225913, 9655.338417284502, 9659.916581490963, 9664.478376929716, 9669.02386121214, 9673.553092474735, 9678.066129377261, 9682.563031100863, 9687.043857346205, 9691.508668331588, 9695.957524791045, 9700.390487972458, 9704.807619635645, 9709.208982050444, 9713.594637994802, 9717.964650752841, 9722.319084112929, 9726.658002365743, 9730.981470302315, 9735.289553212104, 9739.582316881017, 9743.859827589464, 9748.122152110394, 9752.369357707319, 9756.60151213235, 9760.818683624211, 9765.020940906268, 9769.208353184542, 9773.38099014572, 9777.53892195518, 9781.682219254972, 9785.810953161854, 9789.92519526528, 9794.025017625403, 9798.110492771084, 9802.181693697881, 9806.238693866062, 9810.281567198586, 9814.31038807912, 9818.325231350023, 9822.32617231035, 9826.313286713841, 9830.28665076694, 9834.246341126778, 9838.192434899176, 9842.125009636651, 9846.044143336423, 9849.949914438415, 9853.842401823264, 9857.721684810333, 9861.587843155718, 9865.440957050278, 9869.281107117637, 9873.108374412222, 9876.922840417283, 9880.724587042925, 9884.51369662414, 9888.290251918854, 9892.054336105957, 9895.80603278337, 9899.54542596609, 9903.272600084243, 9906.98763998117, 9910.690630911473, 9914.38165853911, 9918.06080893548, 9921.7281685775, 9925.38382434571, 9929.027863522391, 9932.660373789653, 9936.281443227574, 9939.891160312318, 9943.489613914277, 9947.076893296213, 9950.653088111407, 9954.218288401833, 9957.772584596314, 9961.316067508715, 9964.848828336122, 9968.370958657048, 9971.882550429646, 9975.383695989922, 9978.874488049969, 9982.355019696206, 9985.825384387635, 9989.2856759541, 9992.735988594559, 9996.176416875382, 9999.60705572863, 10003.028000450387, 10006.439346699068, 10009.841190493758, 10013.233628212562, 10016.61675659096, 10019.990672720185, 10023.355474045618, 10026.71125836517, 10030.058123827715, 10033.396168931513, 10036.725492522643, 10040.046193793478, 10043.358372281144, 10046.662127866017, 10049.957560770215, 10053.244771556123, 10056.523861124924, 10059.794930715147, 10063.058081901234, 10066.313416592118, 10069.561037029824, 10072.80104578808, 10076.033545770946, 10079.25864021147, 10082.476432670344, 10085.687027034586, 10088.890527516252, 10092.087038651136, 10095.27666529752, 10098.45951263492, 10101.635686162857, 10104.805291699658, 10107.968435381254, 10111.12522366001, 10114.275763303584, 10117.420161393777, 10120.55852532543, 10123.690962805333, 10126.817581851139, 10129.938490790319, 10133.053798259134, 10136.163613201606, 10139.268044868539, 10142.367202816544, 10145.461196907085, 10148.550137305561, 10151.63413448038, 10154.713299202092, 10157.787742542512, 10160.857575873886, 10163.922910868063, 10166.983859495704, 10170.04053402551, 10173.09304702345, 10176.141511352065, 10179.18604016973, 10182.226746929984, 10185.263745380877, 10188.297149564321, 10191.327073815486, 10194.353632762213, 10197.37694132444, 10200.397114713678, 10203.41426843248, 10206.428518273962, 10209.439980321335, 10212.448770947456, 10215.455006814433, 10218.45880487321, 10221.460282363223, 10224.459556812048, 10227.456746035106, 10230.451968135352, 10233.445341503042, 10236.436984815475, 10239.427017036805, 10242.415557417855, 10245.402725495958, 10248.388641094842, 10251.373424324522, 10254.357195581239, 10257.34007554741, 10260.32218519161, 10263.303645768601, 10266.284578819352, 10269.265106171124, 10272.245349937568, 10275.225432518839, 10278.205476601772, 10281.185605160044, 10284.16594145442, 10287.146609032958, 10290.12773173132, 10293.109433673057, 10296.091839269937, 10299.07507322233, 10302.059260519585, 10305.044526440464, 10308.03099655359, 10311.018796717948, 10314.00805308339, 10316.99889209119, 10319.991440474623, 10322.985825259588, 10325.982173765233, 10328.980613604654, 10331.981272685587, 10334.984279211163, 10337.989761680672, 10340.997848890378, 10344.008669934356, 10347.022354205363, 10350.039031395752, 10353.058831498409, 10356.081884807727, 10359.108321920621, 10362.138273737555, 10365.171871463648, 10368.209246609753, 10371.25053099363, 10374.295856741115, 10377.345356287346, 10380.399162378002, 10383.457408070615, 10386.520226735873, 10389.587752058982, 10392.660118041089, 10395.73745900068, 10398.819909575079, 10401.907604721937, 10405.000679720792, 10408.099270174638, 10411.203512011556, 10414.313541486366, 10417.429495182323, 10420.551510012858, 10423.679723223337, 10426.814272392898, 10429.955295436275, 10433.102930605704, 10436.257316492856, 10439.418592030794, 10442.586896495994, 10445.762369510392, 10448.945151043474, 10452.135381414415, 10455.333201294237, 10458.538751708043, 10461.752174037258, 10464.973610021932, 10468.203201763086, 10471.441091725086, 10474.687422738074, 10477.942338000434, 10481.205981081306, 10484.478495923138, 10487.760026844291, 10491.050718541679, 10494.350716093457, 10497.66016496175, 10500.979210995443, 10504.308000432991, 10507.6466799053, 10510.995396438622, 10514.354297457543, 10517.723530787976, 10521.103244660211, 10524.493587712032, 10527.894708991851, 10531.30675796192, 10534.72988450157, 10538.164238910504, 10541.60997191215, 10545.067234657039, 10548.536178726265, 10552.016956134967, 10555.509719335874, 10559.014621222905, 10562.531815134811, 10566.061454858862, 10569.603694634623, 10573.158689157723, 10576.726593583735, 10580.307563532064, 10583.901755089932, 10587.509324816361, 10591.130429746276, 10594.765227394604, 10598.413875760463, 10602.076533331403, 10605.75335908769, 10609.444512506652, 10613.15015356709, 10616.870442753745, 10620.605541061801, 10624.355610001483, 10628.120811602685, 10631.90130841967, 10635.697263535832, 10639.508840568496, 10643.336203673825, 10647.179517551727, 10651.03894745089, 10654.914659173823, 10658.806819081987, 10662.715594100999, 10666.641151725873, 10670.583660026341 };
    double dis[441] = { 0.25,   0.5 ,   0.75,   1.  ,   1.25,   1.5 ,   1.75,   2.  ,
         2.25,   2.5 ,   2.75,   3.  ,   3.25,   3.5 ,   3.75,   4.  ,
         4.25,   4.5 ,   4.75,   5.  ,   5.25,   5.5 ,   5.75,   6.  ,
         6.25,   6.5 ,   6.75,   7.  ,   7.25,   7.5 ,   7.75,   8.  ,
         8.25,   8.5 ,   8.75,   9.  ,   9.25,   9.5 ,   9.75,  10.  ,
        10.25,  10.5 ,  10.75,  11.  ,  11.25,  11.5 ,  11.75,  12.  ,
        12.25,  12.5 ,  12.75,  13.  ,  13.25,  13.5 ,  13.75,  14.  ,
        14.25,  14.5 ,  14.75,  15.  ,  15.25,  15.5 ,  15.75,  16.  ,
        16.25,  16.5 ,  16.75,  17.  ,  17.25,  17.5 ,  17.75,  18.  ,
        18.25,  18.5 ,  18.75,  19.  ,  19.25,  19.5 ,  19.75,  20.  ,
        20.25,  20.5 ,  20.75,  21.  ,  21.25,  21.5 ,  21.75,  22.  ,
        22.25,  22.5 ,  22.75,  23.  ,  23.25,  23.5 ,  23.75,  24.  ,
        24.25,  24.5 ,  24.75,  25.  ,  25.25,  25.5 ,  25.75,  26.  ,
        26.25,  26.5 ,  26.75,  27.  ,  27.25,  27.5 ,  27.75,  28.  ,
        28.25,  28.5 ,  28.75,  29.  ,  29.25,  29.5 ,  29.75,  30.  ,
        30.25,  30.5 ,  30.75,  31.  ,  31.25,  31.5 ,  31.75,  32.  ,
        32.25,  32.5 ,  32.75,  33.  ,  33.25,  33.5 ,  33.75,  34.  ,
        34.25,  34.5 ,  34.75,  35.  ,  35.25,  35.5 ,  35.75,  36.  ,
        36.25,  36.5 ,  36.75,  37.  ,  37.25,  37.5 ,  37.75,  38.  ,
        38.25,  38.5 ,  38.75,  39.  ,  39.25,  39.5 ,  39.75,  40.  ,
        40.25,  40.5 ,  40.75,  41.  ,  41.25,  41.5 ,  41.75,  42.  ,
        42.25,  42.5 ,  42.75,  43.  ,  43.25,  43.5 ,  43.75,  44.  ,
        44.25,  44.5 ,  44.75,  45.  ,  45.25,  45.5 ,  45.75,  46.  ,
        46.25,  46.5 ,  46.75,  47.  ,  47.25,  47.5 ,  47.75,  48.  ,
        48.25,  48.5 ,  48.75,  49.  ,  49.25,  49.5 ,  49.75,  50.  ,
        50.25,  50.5 ,  50.75,  51.  ,  51.25,  51.5 ,  51.75,  52.  ,
        52.25,  52.5 ,  52.75,  53.  ,  53.25,  53.5 ,  53.75,  54.  ,
        54.25,  54.5 ,  54.75,  55.  ,  55.25,  55.5 ,  55.75,  56.  ,
        56.25,  56.5 ,  56.75,  57.  ,  57.25,  57.5 ,  57.75,  58.  ,
        58.25,  58.5 ,  58.75,  59.  ,  59.25,  59.5 ,  59.75,  60.  ,
        60.25,  60.5 ,  60.75,  61.  ,  61.25,  61.5 ,  61.75,  62.  ,
        62.25,  62.5 ,  62.75,  63.  ,  63.25,  63.5 ,  63.75,  64.  ,
        64.25,  64.5 ,  64.75,  65.  ,  65.25,  65.5 ,  65.75,  66.  ,
        66.25,  66.5 ,  66.75,  67.  ,  67.25,  67.5 ,  67.75,  68.  ,
        68.25,  68.5 ,  68.75,  69.  ,  69.25,  69.5 ,  69.75,  70.  ,
        70.25,  70.5 ,  70.75,  71.  ,  71.25,  71.5 ,  71.75,  72.  ,
        72.25,  72.5 ,  72.75,  73.  ,  73.25,  73.5 ,  73.75,  74.  ,
        74.25,  74.5 ,  74.75,  75.  ,  75.25,  75.5 ,  75.75,  76.  ,
        76.25,  76.5 ,  76.75,  77.  ,  77.25,  77.5 ,  77.75,  78.  ,
        78.25,  78.5 ,  78.75,  79.  ,  79.25,  79.5 ,  79.75,  80.  ,
        80.25,  80.5 ,  80.75,  81.  ,  81.25,  81.5 ,  81.75,  82.  ,
        82.25,  82.5 ,  82.75,  83.  ,  83.25,  83.5 ,  83.75,  84.  ,
        84.25,  84.5 ,  84.75,  85.  ,  85.25,  85.5 ,  85.75,  86.  ,
        86.25,  86.5 ,  86.75,  87.  ,  87.25,  87.5 ,  87.75,  88.  ,
        88.25,  88.5 ,  88.75,  89.  ,  89.25,  89.5 ,  89.75,  90.  ,
        90.25,  90.5 ,  90.75,  91.  ,  91.25,  91.5 ,  91.75,  92.  ,
        92.25,  92.5 ,  92.75,  93.  ,  93.25,  93.5 ,  93.75,  94.  ,
        94.25,  94.5 ,  94.75,  95.  ,  95.25,  95.5 ,  95.75,  96.  ,
        96.25,  96.5 ,  96.75,  97.  ,  97.25,  97.5 ,  97.75,  98.  ,
        98.25,  98.5 ,  98.75,  99.  ,  99.25,  99.5 ,  99.75, 100.  ,
       100.25, 100.5 , 100.75, 101.  , 101.25, 101.5 , 101.75, 102.  ,
       102.25, 102.5 , 102.75, 103.  , 103.25, 103.5 , 103.75, 104.  ,
       104.25, 104.5 , 104.75, 105.  , 105.25, 105.5 , 105.75, 106.  ,
       106.25, 106.5 , 106.75, 107.  , 107.25, 107.5 , 107.75, 108.  ,
       108.25, 108.5 , 108.75, 109.  , 109.25, 109.5 , 109.75, 110.  ,
       110.25 };

    float Hu_val[5] = { -1000, -200, 0,  340 ,1000 };
    //float ct_val[5] = { 4.1873695613478255, 83.58913886388214, 97.9687638053712, 125.55489763914889 , 172.6599470342564 };
    float ct_val[5] = { 10.1873695613478255, 77.62910214809679, 99.9687638053712, 127.946734685615 , 179.65494217014785 };
    //float Hu_val[5] = { 0 ,1000 };
};
#endif //__Catphan_Focus_S_PGA6_Binning2__hpp_