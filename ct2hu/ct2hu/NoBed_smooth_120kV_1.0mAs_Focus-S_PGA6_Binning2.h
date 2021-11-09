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
    float K_val[441] = { 5262.355899304639, 5268.375410615464, 5274.3978041332575, 5280.423047022241, 5286.451106236473, 5292.481948519299, 5298.515540402816, 5304.55184820733, 5310.59083804082, 5316.63247579841, 5322.676727161836, 5328.723557598927, 5334.772932363086, 5340.824816492764, 5346.8791748109625, 5352.935971924712, 5358.995172224579, 5365.056739884155, 5371.12063885957, 5377.186832889, 5383.255285492171, 5389.325959969891, 5395.398819403561, 5401.473826654702, 5407.550944364491, 5413.630134953295, 5419.711360620212, 5425.794583342612, 5431.879764875692, 5437.966866752031, 5444.055850281145, 5450.146676549059, 5456.239306417874, 5462.3337005253425, 5468.42981928445, 5474.527622882999, 5480.627071283205, 5486.72812422129, 5492.830741207087, 5498.934881523647, 5505.040504226855, 5511.147568145048, 5517.25603187864, 5523.365853799757, 5529.476992051871, 5535.589404549447, 5541.703048977584, 5547.81788279169, 5553.933863217119, 5560.050947248861, 5566.169091651203, 5572.288252957423, 5578.408387469461, 5584.529451257635, 5590.651400160321, 5596.77418978368, 5602.8977755013575, 5609.022112454219, 5615.147155550066, 5621.272859463382, 5627.399178635076, 5633.5260672722225, 5639.653479347832, 5645.781368600608, 5651.909688534727, 5658.038392419607, 5664.167433289709, 5670.296763944323, 5676.426336947379, 5682.556104627249, 5688.686019076575, 5694.816032152093, 5700.946095474464, 5707.076160428127, 5713.206178161143, 5719.336099585058, 5725.465875374769, 5731.595455968405, 5737.7247915672115, 5743.853832135441, 5749.9825274002615, 5756.110826851664, 5762.238679742386, 5768.366035087839, 5774.49284166605, 5780.619048017601, 5786.7446024456, 5792.869453015637, 5798.99354755576, 5805.116833656466, 5811.239258670688, 5817.360769713806, 5823.481313663655, 5829.600837160556, 5835.719286607343, 5841.836608169408, 5847.952747774755, 5854.0676511140655, 5860.18126364077, 5866.29353057113, 5872.404396884337, 5878.513807322614, 5884.621706391333, 5890.728038359136, 5896.832747258077, 5902.935776883766, 5909.03707079553, 5915.1365723165745, 5921.234224534174, 5927.329970299854, 5933.423752229597, 5939.515512704055, 5945.605193868772, 5951.6927376344265, 5957.778085677069, 5963.861179438388, 5969.941960125978, 5976.020368713623, 5982.096345941585, 5988.169832316923, 5994.24076811379, 6000.309093373784, 6006.374747906273, 6012.43767128876, 6018.497802867242, 6024.5550817565945, 6030.6094468409565, 6036.6608367741355, 6042.709189980026, 6048.754444653035, 6054.796538758523, 6060.835410033259, 6066.870995985889, 6072.90323389741, 6078.9320608216685, 6084.95741358586, 6090.979228791056, 6096.997442812725, 6103.011991801293, 6109.022811682682, 6115.029838158902, 6121.03300670862, 6127.032252587772, 6133.027510830168, 6139.01871624812, 6145.0058034330805, 6150.988706756303, 6156.967360369505, 6162.941698205544, 6168.911653979127, 6174.87716118751, 6180.838153111226, 6186.7945628148245, 6192.746323147618, 6198.693366744459, 6204.635626026513, 6210.573033202061, 6216.505520267305, 6222.433019007196, 6228.355460996274, 6234.272777599522, 6240.184899973234, 6246.0917590659055, 6251.993285619123, 6257.889410168488, 6263.780063044542, 6269.665174373709, 6275.544674079258, 6281.418491882276, 6287.286557302665, 6293.1487996601345, 6299.005148075233, 6304.855531470383, 6310.699878570925, 6316.538117906194, 6322.370177810599, 6328.19598642472, 6334.0154716964225, 6339.828561381989, 6345.635183047263, 6351.435264068812, 6357.228731635101, 6363.015512747694, 6368.795534222451, 6374.568722690764, 6380.335004600794, 6386.094306218724, 6391.846553630039, 6397.591672740815, 6403.329589279017, 6409.060228795828, 6414.783516666986, 6420.499378094137, 6426.2077381062045, 6431.908521560779, 6437.601653145519, 6443.287057379573, 6448.964658615011, 6454.634381038286, 6460.296148671691, 6465.9498853748555, 6471.595514846241, 6477.232960624658, 6482.862146090811, 6488.482994468838, 6494.095428827887, 6499.699372083696, 6505.294747000201, 6510.8814761911435, 6516.459482121714, 6522.0286871102035, 6527.589013329665, 6533.1403828096045, 6538.6827174376795, 6544.215938961415, 6549.739968989946, 6555.254728995759, 6560.760140316467, 6566.256124156594, 6571.742601589371, 6577.219493558562, 6582.686720880293, 6588.144204244904, 6593.5918642188235, 6599.029621246444, 6604.457395652028, 6609.875107641632, 6615.28267730503, 6620.680024617673, 6626.067069442652, 6631.443731532689, 6636.809930532129, 6642.165585978968, 6647.510617306876, 6652.844943847258, 6658.1684848313125, 6663.481159392122, 6668.782886566745, 6674.073585298342, 6679.353174438296, 6684.621572748373, 6689.878698902879, 6695.1244714908435, 6700.358809018219, 6705.5816299100925, 6710.792852512912, 6715.9923950967395, 6721.180175857506, 6726.356112919291, 6731.520124336617, 6736.6721280967595, 6741.812042122068, 6746.93978427231, 6752.055272347027, 6757.158424087906, 6762.249157181166, 6767.327389259962, 6772.393037906806, 6777.446020655996, 6782.486254996065, 6787.513658372255, 6792.528148188978, 6797.529641812331, 6802.518056572588, 6807.493309766737, 6812.45531866101, 6817.404000493443, 6822.339272476441, 6827.261051799363, 6832.1692556311145, 6837.063801122769, 6841.9446054101845, 6846.81158561665, 6851.664658855534, 6856.5037422329615, 6861.328752850487, 6866.139607807798, 6870.9362242054185, 6875.71851914744, 6880.4864097442505, 6885.239813115288, 6889.978646391806, 6894.702826719648, 6899.4122712620365, 6904.106897202376, 6908.78662174707, 6913.451362128346, 6918.1010356071, 6922.735559475745, 6927.354851061078, 6931.958827727161, 6936.547406878203, 6941.120505961468, 6945.678042470185, 6950.2199339464705, 6954.746097984272, 6959.2564522323055, 6963.750914397023, 6968.229402245576, 6972.691833608802, 6977.138126384208, 6981.568198538979, 6985.981968112988, 6990.3793532218215, 6994.760272059804, 6999.124642903052, 7003.472384112517, 7007.803414137056, 7012.117651516494, 7016.415014884716, 7020.695422972745, 7024.958794611853, 7029.205048736658, 7033.4341043882505, 7037.645880717313, 7041.840296987253, 7046.0172725773455, 7050.176726985886, 7054.318579833341, 7058.442750865516, 7062.54915995673, 7066.63772711299, 7070.708372475178, 7074.761016322249, 7078.795579074423, 7082.811981296396, 7086.81014370055, 7090.789987150174, 7094.751432662685, 7098.694401412856, 7102.618814736055, 7106.524594131486, 7110.411661265428, 7114.2799379744865, 7118.129346268857, 7121.959808335571, 7125.771246541767, 7129.563583437953, 7133.33674176128, 7137.090644438816, 7140.825214590822, 7144.540375534032, 7148.236050784938, 7151.912164063074, 7155.568639294304, 7159.205400614116, 7162.82237237091, 7166.41947912929, 7169.996645673367, 7173.553797010052, 7177.090858372348, 7180.607755222654, 7184.104413256068, 7187.580758403677, 7191.036716835858, 7194.4722149655845, 7197.887179451716, 7201.281537202301, 7204.65521537787, 7208.008141394736, 7211.340242928288, 7214.651447916277, 7217.9416845621145, 7221.210881338158, 7224.458966989001, 7227.685870534746, 7230.891521274295, 7234.075848788629, 7237.238782944067, 7240.380253895556, 7243.500192089921, 7246.598528269137, 7249.675193473583, 7252.730119045296, 7255.763236631216, 7258.774478186437, 7261.763775977433, 7264.731062585301, 7267.676270908977, 7270.599334168465, 7273.5001859080385, 7276.37875999946, 7279.234990645167, 7282.068812381473, 7284.880160081747, 7287.668968959594, 7290.435174572017, 7293.178712822583, 7295.899519964573, 7298.597532604121, 7301.27268770335, 7303.9249225834965, 7306.554174928023, 7309.160382785723, 7311.743484573816, 7314.303419081027, 7316.840125470665, 7319.35354328368, 7321.843612441716, 7324.31027325015, 7326.753466401118, 7329.173132976528, 7331.569214451069, 7333.941652695193, 7336.2903899781, 7338.615368970698, 7340.916532748553, 7343.193824794828, 7345.447189003204, 7347.6765696807915, 7349.881911551025, 7352.063159756542, 7354.2202598620415, 7356.353157857148, 7358.461800159232, 7360.5461336162325, 7362.606105509467, 7364.641663556402, 7366.652755913438, 7368.639331178654, 7370.601338394545, 7372.53872705074, 7374.4514470867025, 7376.33944889442, 7378.202683321055, 7380.041101671608, 7381.854655711536, 7383.643297669363, 7385.406980239273, 7387.14565658368, 7388.85928033578, 7390.547805602079, 7392.211186964914, 7393.849379484935, 7395.462338703579, 7397.050020645525, 7398.612381821119, 7400.14937922878, 7401.660970357391, 7403.1471131886665, 7404.607766199487 };
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

    //float ct_val[5] = { 56.378758215267396, 91.36336141491158, 99.2376656657246, 118.74763914690462, 147.44908198448616 };
    float Hu_val[5] = { -1000, -200, 0,  340 ,1000 };
    //float ct_val[5] = { 39.33624232418327, 88.0, 99.27896942857213, 119.67789828497672 , 153.3050211382492 };
    float ct_val[5] = { 42, 88.0, 99.27896942857213, 119.67789828497672 , 153.3050211382492 };
    //float Hu_val[5] = { 0 ,1000 };
};
#endif //__Catphan_Focus_S_PGA6_Binning2__hpp_