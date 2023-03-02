float4 VS(float4 inPos : POSITION) : SV_POSITION
{
    return inPos;
}

float4 PS( float4 Pos : SV_POSITION ) : SV_Target
{
    return float4( 1.0f, 1.0f, 0.0f, 1.0f );
}