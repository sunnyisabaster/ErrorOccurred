#ifndef _Catphan_100kV_2mAs_Focus_S_PGA6_Binning2_hpp_
#define _Catphan_100kV_2mAs_Focus_S_PGA6_Binning2_hpp_

class Catphan_Focus_S_PGA6_Binning2_100_2 {
public:
    Catphan_Focus_S_PGA6_Binning2_100_2() {

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
    float K_val[441] = { 6061.236772070723, 6064.579779650851, 6067.935952256181, 6071.305251952545, 6074.687640676304, 6078.083080231764, 6081.491532288594, 6084.91295837924, 6088.347319896343, 6091.794578090142, 6095.254694065885, 6098.727628781238, 6102.213343043685, 6105.711797507925, 6109.2229526732835, 6112.746768881094, 6116.2832063120995, 6119.832224983844, 6123.393784748059, 6126.9678452880535, 6130.554366116091, 6134.153306570777, 6137.764625814439, 6141.388282830493, 6145.024236420833, 6148.672445203188, 6152.332867608495, 6156.005461878271, 6159.690186061968, 6163.386998014344, 6167.095855392808, 6170.816715654791, 6174.549536055089, 6178.29427364322, 6182.050885260767, 6185.819327538732, 6189.599556894872, 6193.391529531044, 6197.195201430544, 6201.010528355441, 6204.837465843916, 6208.675969207587, 6212.525993528842, 6216.38749365817, 6220.260424211475, 6224.14473956741, 6228.040393864691, 6231.947340999418, 6235.865534622387, 6239.794928136412, 6243.735474693625, 6247.6871271928, 6251.649838276651, 6255.623560329139, 6259.608245472781, 6263.603845565951, 6267.610312200179, 6271.627596697449, 6275.655650107504, 6279.694423205129, 6283.743866487463, 6287.803930171273, 6291.874564190262, 6295.955718192349, 6300.047341536963, 6304.149383292332, 6308.261792232765, 6312.384516835943, 6316.517505280205, 6320.660705441828, 6324.814064892313, 6328.9775308956705, 6333.1510504057, 6337.334570063272, 6341.528036193614, 6345.731394803589, 6349.9445915789765, 6354.167571881757, 6358.400280747389, 6362.642662882097, 6366.894662660151, 6371.156224121147, 6375.42729096729, 6379.707806560685, 6383.997713920612, 6388.296955720817, 6392.605474286799, 6396.923211593096, 6401.250109260575, 6405.586108553723, 6409.9311503779345, 6414.285175276815, 6418.648123429466, 6423.019934647793, 6427.400548373797, 6431.789903676885, 6436.187939251163, 6440.5945934127585, 6445.00980409712, 6449.433508856333, 6453.865644856439, 6458.306148874753, 6462.7549572971875, 6467.212006115578, 6471.677230925019, 6476.150566921191, 6480.631948897706, 6485.121311243447, 6489.618587939922, 6494.123712558608, 6498.636618258318, 6503.157237782558, 6507.685503456901, 6512.221347186353, 6516.7647004527425, 6521.315494312101, 6525.873659392055, 6530.439125889229, 6535.011823566648, 6539.59168175115, 6544.178629330804, 6548.772594752346, 6553.373506018602, 6557.981290685936, 6562.595875861703, 6567.217188201702, 6571.845153907652, 6576.479698724663, 6581.1207479387185, 6585.76822637418, 6590.422058391286, 6595.082167883665, 6599.748478275865, 6604.420912520887, 6609.099393097733, 6613.783842008956, 6618.4741807782375, 6623.170330447965, 6627.872211576821, 6632.57974423739, 6637.292848013773, 6642.011441999223, 6646.735444793777, 6651.46477450192, 6656.199348730256, 6660.939084585183, 6665.6838986706025, 6670.433707085621, 6675.188425422286, 6679.947968763326, 6684.712251679908, 6689.481188229415, 6694.254691953236, 6699.032675874571, 6703.815052496264, 6708.601733798632, 6713.39263123734, 6718.187655741264, 6722.986717710402, 6727.789727013779, 6732.596592987385, 6737.407224432129, 6742.221529611812, 6747.039416251124, 6751.860791533656, 6756.685562099937, 6761.513634045493, 6766.344912918923, 6771.179303720005, 6776.016710897818, 6780.857038348887, 6785.700189415361, 6790.546066883197, 6795.394572980392, 6800.2456093752135, 6805.09907717448, 6809.954876921846, 6814.81290859613, 6819.673071609655, 6824.535264806627, 6829.399386461532, 6834.265334277569, 6839.133005385102, 6844.002296340146, 6848.873103122887, 6853.74532113622, 6858.618845204324, 6863.493569571268, 6868.3693878996455, 6873.246193269238, 6878.12387817572, 6883.002334529384, 6887.881453653903, 6892.761126285133, 6897.641242569937, 6902.521692065055, 6907.402363735997, 6912.283145955983, 6917.163926504909, 6922.044592568355, 6926.925030736629, 6931.805127003841, 6936.684766767029, 6941.563834825306, 6946.44221537906, 6951.319792029188, 6956.196447776363, 6961.072065020352, 6965.9465255593705, 6970.819710589472, 6975.6915007039925, 6980.561775893024, 6985.430415542937, 6990.2972984359485, 6995.162302749726, 7000.025306057046, 7004.886185325487, 7009.744816917177, 7014.601076588581, 7019.4548394903395, 7024.3059801671425, 7029.154372557675, 7033.999889994579, 7038.842405204492, 7043.681790308121, 7048.517916820363, 7053.350655650488, 7058.179877102364, 7063.00545087473, 7067.8272460615335, 7072.645131152311, 7077.458974032617, 7082.268641984526, 7087.074001687162, 7091.8749192173045, 7096.67126005004, 7101.462889059467, 7106.249670519464, 7111.031468104514, 7115.808144890574, 7120.579563356021, 7125.345585382644, 7130.106072256697, 7134.8608846700145, 7139.609882721185, 7144.352925916785, 7149.089873172673, 7153.820582815352, 7158.544912583384, 7163.262719628873, 7167.973860519014, 7172.6781912377, 7177.375567187196, 7182.065843189876, 7186.748873490037, 7191.424511755752, 7196.092611080824, 7200.753023986781, 7205.405602424949, 7210.050197778592, 7214.686660865119, 7219.314841938364, 7223.934590690931, 7228.5457562566135, 7233.148187212874, 7237.741731583415, 7242.326236840801, 7246.901549909164, 7251.46751716698, 7256.023984449914, 7260.570797053743, 7265.107799737357, 7269.634836725822, 7274.151751713533, 7278.658387867425, 7283.154587830284, 7287.640193724109, 7292.115047153569, 7296.578989209526, 7301.031860472644, 7305.47350101707, 7309.903750414199, 7314.322447736512, 7318.7294315615, 7323.124539975662, 7327.507610578584, 7331.8784804871075, 7336.2369863395625, 7340.5829643001, 7344.916250063088, 7349.236678857611, 7353.544085452031, 7357.838304158643, 7362.119168838412, 7366.386512905794, 7370.6401693336375, 7374.879970658173, 7379.105748984083, 7383.317335989662, 7387.514562932059, 7391.6972606526015, 7395.865259582212, 7400.018389746906, 7404.156480773379, 7408.279361894677, 7412.386861955953, 7416.478809420313, 7420.555032374757, 7424.615358536182, 7428.659615257505, 7432.687629533848, 7436.699228008825, 7440.694236980913, 7444.672482409906, 7448.633789923468, 7452.577984823765, 7456.504892094191, 7460.4143364061765, 7464.306142126096, 7468.180133322251, 7472.036133771955, 7475.873966968698, 7479.693456129406, 7483.494424201779, 7487.276693871734, 7491.0400875709265, 7494.784427484359, 7498.509535558087, 7502.215233507005, 7505.901342822728, 7509.567684781558, 7513.214080452542, 7516.84035070561, 7520.446316219819, 7524.031797491663, 7527.596614843492, 7531.140588431999, 7534.6635382568165, 7538.165284169178, 7541.645645880686, 7545.104442972152, 7548.541494902536, 7551.9566210179655, 7555.3496405608375, 7558.720372679016, 7562.068636435109, 7565.394250815831, 7568.697034741451, 7571.976807075327, 7575.233386633522, 7578.466592194508, 7581.6762425089455, 7584.862156309554, 7588.024152321064, 7591.162049270243, 7594.275665896015, 7597.364820959653, 7600.4293332550515, 7603.469021619085, 7606.48370494204, 7609.473202178131, 7612.437332356087, 7615.375914589823, 7618.28876808919, 7621.175712170788, 7624.03656626887, 7626.871149946312, 7629.679282905661, 7632.460785000254, 7635.21547624541, 7637.9431768296945, 7640.643707126254, 7643.316887704229, 7645.962539340215, 7648.580483029819, 7651.170539999264, 7653.73253171707, 7656.2662799057925, 7658.771606553842, 7661.248333927343, 7663.696284582079, 7666.11528137549, 7668.505147478722, 7670.865706388758, 7673.196781940582, 7675.4981983194275, 7677.7697800730575, 7680.011352124116, 7682.222739782531, 7684.4037687579685, 7686.554265172339, 7688.674055572351, 7690.762966942124, 7692.8208267158425, 7694.847462790462, 7696.842703538444, 7698.806377820569, 7700.738314998759, 7702.63834494896, 7704.506298074063, 7706.342005316859, 7708.1452981730345, 7709.916008704208, 7711.6539695509955, 7713.359013946108, 7715.030975727488, 7716.669689351474, 7718.274989905988, 7719.846713123759, 7721.384695395573, 7722.888773783531, 7724.35878603436, 7725.794570592709, 7727.195966614499, 7728.562813980266, 7729.894953308533, 7731.1922259691955, 7732.454474096911, 7733.681540604518, 7734.873269196442, 7736.029504382133, 7737.150091489487, 7738.234876678286, 7739.2837069536445, 7740.296430179437, 7741.272895091749, 7742.212951312301, 7743.116449361896, 7743.983240673832, 7744.81317760733, 7745.606113460931, 7746.361902485902, 7747.0803998996125, 7747.761461898904, 7748.404945673433, 7749.010709419011, 7749.5786123509, 7750.108514717107, 7750.600277811637, 7751.053763987734, 7751.468836671068 };
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
    //float ct_val[5] = { 35.102540321935344, 87.77169466513645, 99.67148849492737, 123.99884968891963 , 162.15271219013286 };
    float ct_val[5] = { 38.102540321935344, 89.77169466513645, 101, 123.99884968891963 , 162.15271219013286 };
    //float Hu_val[5] = { 0 ,1000 };
};
#endif //__Catphan_Focus_S_PGA6_Binning2__hpp_